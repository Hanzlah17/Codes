import tkinter as tk
from tkinter import messagebox, filedialog, ttk
import pickle
import os

class PIAManagement:
    def __init__(self, root):
        self.root = root
        self.root.title("PIA Seat Reservation System")
        
        self.seating_classes = ["Business", "Economy", "Student"]
        self.seat_counts = {"Business": 12, "Economy": 24, "Student": 8}
        self.pricing = {"Business": 200000, "Economy": 100000, "Student": 40000}
        self.max_luggage_weight = 100  # Passenger luggage limit in kg
        self.max_cargo_capacity = 2000  # Plane cargo capacity in kg
        
        self.planes = {1: []}  # Initially give user 1 plane
        self.plane_windows = {1: None}
        self.current_plane = tk.IntVar(value=1)  # Default to plane 1
        self.current_selection = None
        self.plane_cargo = {1: 0}  # Cargo weight for each plane
        
        self.load_isidata()
        self.create_widgets()
        
    def load_isidata(self):
        self.isi_data = {}
        file_path = filedialog.askopenfilename(defaultextension=".txt", filetypes=[("text file", "*.txt")]) 
        if os.path.exists(file_path):
            with open(file_path, "r") as f:
                for line in f:
                    parts = line.strip().split()
                    if len(parts) == 2:
                        citizen_id, status = parts
                        self.isi_data[citizen_id] = status
        else:
            messagebox.showwarning("Warning", "isidata.txt file not found. All passengers will be marked as UNKNOWN.")
        
    def create_widgets(self):
        # Create dropdown menu for plane selection
        plane_label = tk.Label(self.root, text="Select Plane:")
        plane_label.grid(row=0, column=0)
        
        self.plane_dropdown = ttk.Combobox(self.root, textvariable=self.current_plane, values=list(self.planes.keys()))
        self.plane_dropdown.grid(row=0, column=1)
        self.plane_dropdown.bind("<<ComboboxSelected>>", self.on_plane_change)
        
        self.add_plane_button = tk.Button(self.root, text="Add Plane", command=self.add_plane)
        self.add_plane_button.grid(row=0, column=2)
        
        # Create buttons
        self.reserve_button = tk.Button(self.root, text="Reserve Seat", command=self.reserve_seat)
        self.reserve_button.grid(row=1, column=0)
        
        self.cancel_button = tk.Button(self.root, text="Cancel Reservation", command=self.cancel_reservation)
        self.cancel_button.grid(row=1, column=1)
        
        self.view_seats_button = tk.Button(self.root, text="View Seats", command=self.view_seats)
        self.view_seats_button.grid(row=1, column=2)
        
        self.save_button = tk.Button(self.root, text="Save State", command=self.save_state)
        self.save_button.grid(row=1, column=3)
        
        self.load_button = tk.Button(self.root, text="Load State", command=self.load_state)
        self.load_button.grid(row=1, column=4)
        
        # Create listboxes for seating classes
        self.listboxes = {}
        for idx, seat_class in enumerate(self.seating_classes):
            lbl = tk.Label(self.root, text=seat_class)
            lbl.grid(row=2, column=idx)
            listbox = tk.Listbox(self.root)
            listbox.grid(row=3, column=idx)
            listbox.bind('<ButtonRelease-1>', self.on_select)
            self.listboxes[seat_class] = listbox
    
    def add_plane(self):
        if len(self.planes) < 5:
            new_plane_number = max(self.planes.keys()) + 1
            self.planes[new_plane_number] = []
            self.plane_windows[new_plane_number] = None
            self.plane_cargo[new_plane_number] = 0
            self.plane_dropdown['values'] = list(self.planes.keys())
            messagebox.showinfo("Success", f"Plane {new_plane_number} added.")
        else:
            messagebox.showerror("Error", "You can only add up to 5 planes.")
    
    def on_plane_change(self, event):
        current_plane = self.current_plane.get()
        self.update_listboxes()
        if self.current_selection:
            self.remove_highlight(self.current_selection)
        self.current_selection = None
        # Close current plane window if open
        for plane, window in self.plane_windows.items():
            if window and window.top.winfo_exists():
                window.top.destroy()
            self.plane_windows[plane] = None
    
    def get_current_plane_passengers(self):
        return self.planes[self.current_plane.get()]
    
    def get_current_plane_cargo(self):
        return self.plane_cargo[self.current_plane.get()]
    
    def reserve_seat(self):
        passengers = self.get_current_plane_passengers()
        ReservationDialog(self.root, passengers, self.listboxes, self.isi_data, self, self.current_plane.get())
    
    def cancel_reservation(self):
        passengers = self.get_current_plane_passengers()
        CancellationDialog(self.root, passengers, self.listboxes, self, self.current_plane.get())
    
    def view_seats(self):
        current_plane = self.current_plane.get()
        if self.plane_windows[current_plane] is None or not self.plane_windows[current_plane].top.winfo_exists():
            self.plane_windows[current_plane] = PlaneWindow(self.root, self.planes[current_plane], self.isi_data, self.pricing, self.seat_counts, self.plane_cargo[current_plane])
        else:
            self.plane_windows[current_plane].refresh()
    
    def save_state(self):
        file_path = filedialog.asksaveasfilename(defaultextension=".pkl", filetypes=[("Pickle files", "*.pkl")])
        if file_path:
            with open(file_path, "wb") as f:
                pickle.dump((self.planes, self.plane_cargo), f)
            messagebox.showinfo("Success", "State saved successfully!")
    
    def load_state(self):
        file_path = filedialog.askopenfilename(defaultextension=".pkl", filetypes=[("Pickle files", "*.pkl")])
        if file_path:
            with open(file_path, "rb") as f:
                self.planes, self.plane_cargo = pickle.load(f)
            self.plane_dropdown['values'] = list(self.planes.keys())
            self.update_listboxes()
            for plane_window in self.plane_windows.values():
                if plane_window:
                    plane_window.refresh()
            messagebox.showinfo("Success", "State loaded successfully!")
    
    def update_listboxes(self):
        for listbox in self.listboxes.values():
            listbox.delete(0, tk.END)
        
        for passenger in self.get_current_plane_passengers():
            self.listboxes[passenger["class"]].insert(tk.END, passenger["name"])
    
    def on_select(self, event):
        widget = event.widget
        selection = widget.curselection()
        
        if selection:
            index = selection[0]
            passenger_name = widget.get(index)
            
            if self.current_selection and self.current_selection["name"] == passenger_name:
                return  # Same item clicked, no need to change highlight
            
            if self.current_selection:
                self.remove_highlight(self.current_selection)
            
            passenger = next((p for p in self.get_current_plane_passengers() if p["name"] == passenger_name), None)
            
            if passenger:
                if self.plane_windows[self.current_plane.get()]:
                    self.plane_windows[self.current_plane.get()].highlight_seat(passenger)
                self.current_selection = passenger
        else:
            if self.current_selection:
                if self.plane_windows[self.current_plane.get()]:
                    self.plane_windows[self.current_plane.get()].remove_highlight(self.current_selection)
                self.current_selection = None

    def remove_highlight(self, passenger):
        if self.plane_windows[self.current_plane.get()]:
            self.plane_windows[self.current_plane.get()].remove_highlight(passenger)
        self.current_selection = None

class ReservationDialog:
    def __init__(self, parent, passengers, listboxes, isi_data, main_app, plane_number):
        self.parent = parent
        self.top = tk.Toplevel(parent)
        self.top.title("Reserve Seat")
        
        self.passengers = passengers
        self.listboxes = listboxes
        self.isi_data = isi_data
        self.main_app = main_app
        self.plane_number = plane_number
        
        self.create_widgets()
        
    def create_widgets(self):
        self.name_label = tk.Label(self.top, text="Name:")
        self.name_label.grid(row=0, column=0)
        self.name_entry = tk.Entry(self.top)
        self.name_entry.grid(row=0, column=1)
        
        self.id_label = tk.Label(self.top, text="ID:")
        self.id_label.grid(row=1, column=0)
        self.id_entry = tk.Entry(self.top)
        self.id_entry.grid(row=1, column=1)
        
        self.class_label = tk.Label(self.top, text="Class:")
        self.class_label.grid(row=2, column=0)
        self.class_var = tk.StringVar(self.top)
        self.class_var.set("Business")
        self.class_menu = tk.OptionMenu(self.top, self.class_var, "Business", "Economy", "Student")
        self.class_menu.grid(row=2, column=1)
        
        self.seat_label = tk.Label(self.top, text="Seat Number:")
        self.seat_label.grid(row=3, column=0)
        self.seat_entry = tk.Entry(self.top)
        self.seat_entry.grid(row=3, column=1)
        
        self.luggage_label = tk.Label(self.top, text="Luggage Weight (kg):")
        self.luggage_label.grid(row=4, column=0)
        self.luggage_entry = tk.Entry(self.top)
        self.luggage_entry.grid(row=4, column=1)
        
        self.submit_button = tk.Button(self.top, text="Submit", command=self.submit)
        self.submit_button.grid(row=5, column=0, columnspan=2)
    
    def submit(self):
        name = self.name_entry.get()
        id_ = self.id_entry.get()
        class_ = self.class_var.get()
        seat_number = self.seat_entry.get()
        luggage_weight = self.luggage_entry.get()
        
        if not id_.isdigit() or len(id_) != 7:
            messagebox.showerror("Error", "ID must be a 7-digit number.")
            self.top.destroy()
            return

        if not seat_number.isdigit() or int(seat_number) < 1 or int(seat_number) > self.main_app.seat_counts[class_]:
            messagebox.showerror("Error", f"Seat number must be a valid number between 1 and {self.main_app.seat_counts[class_]}.")
            self.top.destroy()
            return
        
        if not luggage_weight.isdigit() or int(luggage_weight) < 0 or int(luggage_weight) > self.main_app.max_luggage_weight:
            messagebox.showerror("Error", f"Luggage weight must be a valid number between 0 and {self.main_app.max_luggage_weight} kg.")
            self.top.destroy()
            return
        
        total_luggage = int(luggage_weight) + self.main_app.get_current_plane_cargo()
        if total_luggage > self.main_app.max_cargo_capacity:
            messagebox.showerror("Error", f"Total luggage weight exceeds the plane's cargo capacity of {self.main_app.max_cargo_capacity} kg.")
            self.top.destroy()
            return
        
        for passenger in self.passengers:
            if passenger["id"] == id_:
                messagebox.showerror("Error", "Passenger with this ID already exists.")
                self.top.destroy()
                return
        
        # Check if seat is already taken
        for passenger in self.passengers:
            if passenger["seat_number"] == seat_number and passenger["class"] == class_:
                messagebox.showerror("Error", "Seat is already taken.")
                self.top.destroy()
                return
        
        status = self.isi_data.get(id_, "UNKNOWN")
        
        self.passengers.append({"name": name, "id": id_, "class": class_, "seat_number": seat_number, "luggage_weight": int(luggage_weight), "status": status})
        self.main_app.plane_cargo[self.plane_number] += int(luggage_weight)
        self.listboxes[class_].insert(tk.END, name)
        
        if self.main_app.plane_windows[self.main_app.current_plane.get()]:
            self.main_app.plane_windows[self.main_app.current_plane.get()].refresh()
        
        self.top.destroy()

class CancellationDialog:
    def __init__(self, parent, passengers, listboxes, main_app, plane_number):
        self.parent = parent
        self.top = tk.Toplevel(parent)
        self.top.title("Cancel Reservation")
        
        self.passengers = passengers
        self.listboxes = listboxes
        self.main_app = main_app
        self.plane_number = plane_number
        
        self.create_widgets()
        
    def create_widgets(self):
        self.id_label = tk.Label(self.top, text="ID:")
        self.id_label.grid(row=0, column=0)
        self.id_entry = tk.Entry(self.top)
        self.id_entry.grid(row=0, column=1)
        
        self.submit_button = tk.Button(self.top, text="Submit", command=self.submit)
        self.submit_button.grid(row=1, column=0, columnspan=2)
    
    def submit(self):
        id_ = self.id_entry.get()
        
        for idx, passenger in enumerate(self.passengers):
            if passenger["id"] == id_:
                seat_class = passenger["class"]
                seat_number = passenger["seat_number"]
                luggage_weight = passenger["luggage_weight"]
                self.listboxes[seat_class].delete(0, tk.END)
                self.passengers.pop(idx)
                self.main_app.plane_cargo[self.plane_number] -= luggage_weight
                self.update_listboxes()
                
                if self.main_app.plane_windows[self.main_app.current_plane.get()]:
                    self.main_app.plane_windows[self.main_app.current_plane.get()].refresh()
                
                self.top.destroy()
                return
        
        messagebox.showerror("Error", "Passenger with this ID does not exist.")
        self.top.destroy()
    
    def update_listboxes(self):
        for listbox in self.listboxes.values():
            listbox.delete(0, tk.END)
        
        for passenger in self.passengers:
            self.listboxes[passenger["class"]].insert(tk.END, passenger["name"])

class PlaneWindow:
    def __init__(self, parent, passengers, isi_data, pricing, seat_counts, cargo_weight):
        self.top = tk.Toplevel(parent)
        self.top.title("Plane Seating")
        self.top.minsize(400, 600)  # Set minimum size
        
        self.passengers = passengers
        self.isi_data = isi_data
        self.pricing = pricing
        self.seat_counts = seat_counts
        self.cargo_weight = cargo_weight
        self.current_highlight = None
        self.create_widgets()
        self.update_seats()
        
    def create_widgets(self):
        self.seating_classes = ["Business", "Economy", "Student"]
        self.color_map = {"CLEAN": "green", "TERRORIST": "red", "UNKNOWN": "orange"}
        
        row = 0
        self.buttons = {}  # Keep track of buttons
        for seat_class in self.seating_classes:
            tk.Label(self.top, text=seat_class, fg="blue").grid(row=row, column=0, columnspan=4, pady=5)
            row += 1
            for seat_num in range(self.seat_counts[seat_class]):
                btn = tk.Button(self.top, text=str(seat_num + 1), state="disabled", width=5, fg="white")
                btn.grid(row=row + seat_num // 4, column=seat_num % 4, padx=5, pady=5)
                self.buttons[(seat_class, seat_num)] = btn
            row += (self.seat_counts[seat_class] // 4) + 1
        
        self.info_label = tk.Label(self.top, text="")
        self.info_label.grid(row=row, column=0, columnspan=4, pady=5)
    
    def update_seats(self):
        for (seat_class, seat_num), btn in self.buttons.items():
            btn.config(bg="gray")
                
        occupied_seats = 0
        revenue = 0
        
        for passenger in self.passengers:
            seat_num = int(passenger["seat_number"]) - 1
            seat_class = passenger["class"]
            status = passenger["status"]
            btn = self.buttons.get((seat_class, seat_num))
            if btn:
                btn.config(bg=self.color_map.get(status, "gray"))
            occupied_seats += 1
            revenue += self.pricing[seat_class]
        
        self.info_label.config(text=f"Seats occupied: {occupied_seats}\nCargo Filled: {self.cargo_weight / 20}%\nRevenue: Rs. {revenue:,}")
    
    def highlight_seat(self, passenger):
        if self.current_highlight:
            self.remove_highlight(self.current_highlight)
        seat_num = int(passenger["seat_number"]) - 1
        seat_class = passenger["class"]
        btn = self.buttons.get((seat_class, seat_num))
        if btn:
            btn.config(bg="yellow")
        self.current_highlight = passenger
    
    def remove_highlight(self, passenger):
        seat_num = int(passenger["seat_number"]) - 1
        seat_class = passenger["class"]
        status = passenger["status"]
        btn = self.buttons.get((seat_class, seat_num))
        if btn:
            btn.config(bg=self.color_map.get(status, "gray"))
        self.current_highlight = None
    
    def refresh(self):
        self.update_seats()

if __name__ == "__main__":
    root = tk.Tk()
    app = PIAManagement(root)
    root.mainloop()
