#include <iostream>
using namespace std;
template <typename T>
class DoublyLinkedList
{
	class node
	{
		T data;
		node* next;
		node* prev;

		friend class DoublyLinkedList;
	public:
		node()
		{
			next = nullptr;
			prev = nullptr;
		}
		void Print()
		{
			cout << "| " << data << " | ";
		}
	};

	node* head;
public:
	DoublyLinkedList()
	{
		head = nullptr;
	}

	node* GetNode(T data)
	{
		node* nn = new node;
		nn->data = data;
		nn->next = nullptr;

		return nn;
	}
	node*& getHead()
	{
		return head;
	}
	void insertAtHead(T d)
	{
		node* nn = new node;
		if (head)
		{
		   nn->next = head;
		   head->prev = nn;	
		}
		nn->data = d;
		head = nn;
	}
	void insertAtTail(T d)
	{
		node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		node* nn = new node;
		nn->data = d;
		nn->prev = temp;
		temp->next = nn;
	}

	void printReverse()
	{
		node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		while (temp)
		{
			temp->Print();
			temp = temp->prev;
		}
	}
	void deleteAtStart()
	{
		node* temp = new node;
		temp = head->next;
		head = temp;
		delete head->prev;
		head->prev = nullptr;
	}
	void deleteAtTail()
	{
		node* temp = new node;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp = temp->prev;
		delete temp->next;
		temp->next = nullptr;
	}
	void Print()
	{
		node* temp = head;
		while (temp)
		{
			temp->Print();
			temp = temp->next;
		}
	}
	~DoublyLinkedList()
	{
		node* temp = head;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
	void swapNodes(int n)
	{
		node* start = head;
		node* end = head;
		while (end->next)
		{
			end = end->next;
		}
		for (int i = 1;i < n;i++)
		{
			start = start->next;
			end = end->prev;
		}
		if (start == end)
		{
			return;
		}
		if (n == 1)
		{
			head = end;
			start->prev = end->prev;
			end->prev->next = start;
			start->next->prev = end;
			end->prev = 0;
		}
		node* temp = start->next;
		start->next = end->next;
		end->next = temp;
		if (n > 1)
		{
			start->prev->next = end;
			end->prev->next = start;
			temp = start->prev;
			start->prev = end->prev;
			end->prev = temp;
			end->next->prev = end;
			start->next->prev = start;
		}

	}
};
int main()
{
	DoublyLinkedList<int> list;
	list.insertAtHead(2);
	list.insertAtHead(3);
	list.insertAtHead(5);
	list.insertAtTail(9);
	list.insertAtTail(10);
	list.insertAtTail(7);
	cout << "LIST:\n";
	list.Print();
	cout << endl;
	cout << "Reversed LIST:\n";
	list.printReverse();
	cout << endl;
	cout << "LIST after swapping nodes at position 2:\n";
	list.swapNodes(2);
	list.Print();
	return 0;
}