//#include<iostream>
//#include<fstream>
//using namespace std;
//int rows = 0;
//int cols = 0;
//
//int getIndex(int r, int c)
//{
//	r--;
//	c--;
//	return ((r * cols) + c);
//}
//class node
//{
//public:
//	int data;
//	node* up;
//	node* down;
//	node* left;
//	node* right;
//	node()
//	{
//		data = 0;
//		up = down = left = right = 0;
//	}
//	int sumOfDigits()
//	{
//		int num = data;
//		int sum = 0;
//		while (num != 0)
//		{
//			sum += num % 10; 
//			num /= 10;
//		}
//		return sum;
//	}
//	int NumOfDigits()
//	{
//		int num = data;
//		int count = 0;
//		if (!num)
//		{
//			return 1;
//		}
//		while (num != 0)
//		{
//			count++;
//			num /= 10;
//		}
//		return count;
//	}
//	int ClueRow()
//	{
//		return (sumOfDigits() % rows) + 1;
//	}
//	int ClueColumn()
//	{
//		return NumOfDigits();
//	}
//	bool isElite(node* temp)
//	{
//		return (this == temp);
//	}
//	void Print()
//	{
//		cout << "| " << data << "| ";
//	}
//};
//class Maze
//{
//private:
//	node* head;
//public:
//	Maze()
//	{
//		head = 0;
//	}
//	void CreateMazeStructure()
//	{
//		head = new node;
//		node* temp = head; //used to iterate in cols
//		node* start = head;//used to iterate in rows
//		for (int i = 0;i < rows;i++)
//		{
//			for (int j = 1;j < cols;j++)
//			{
//				node* nn = new node;
//				temp->right = nn;
//				nn->left = temp;
//				temp = temp->right;
//
//			}
//			if (rows > 1 && i < rows - 1)
//			{
//				node* current = new node;
//				start->down = current;
//				current->up = start;
//				start = current;
//				temp = current;
//			}
//		}
//		//making remaining connections
//		temp = head->right;
//		start = head->down;
//		while (start)
//		{
//			node* current = start->right;
//			while (temp)
//			{
//				temp->down = current;
//				current->up = temp;
//				temp = temp->right;
//				current = current->right;
//			}
//			temp = start->right;
//			start = start->down;
//		}
//	}
//	void Read(string filename)
//	{
//		ifstream file;
//		file.open(filename);
//		if (!file.is_open())
//		{
//			cout << "Failed to access file\n";
//			return;
//		}
//		char input;
//		while (file.get(input))
//		{
//			if (input == ',')
//			{
//				cols++;
//			}
//			else if (input == '\n')
//			{
//				rows++;
//				cols = 0;
//			}
//		}
//		cols++;
//		rows++;
//		CreateMazeStructure();
//		file.clear();
//		file.seekg(0, ios::beg);
//		int fileInput = 0;
//		node* temp = head;
//		node* start = head;
//		for (int i = 0;i < rows;i++)
//		{
//			for (int j = 0;j < cols;j++)
//			{
//				file >> fileInput;
//				temp->data = fileInput;
//				temp = temp->right; 
//				file.ignore(1);
//			}
//			temp = start->down;
//			start = start->down;
//		}
//		file.close();
//	}
//	void Print()
//	{
//		node* temp = head;
//		node* start = head;
//		for (int i = 0;i < rows;i++)
//		{
//			for (int j = 0;j < cols;j++)
//			{
//				cout << "| " << temp->data << " |     ";
//				temp = temp->right;
//			}
//			cout << endl << endl << endl << endl;
//			temp = start->down;
//			start = start->down;
//		}
//	}
//	void TraverseNode(node*& temp, int r, int c)//takes the pointer to location provided by clue
//	{
//		temp = head;
//		node* current = head;
//		node* start = head->down;
//		if (r == 1)
//		{
//			for (int i = 1;i < c;i++)
//			{
//				temp = temp->right;
//			}
//			return;
//		}
//		for (int i = 0;i < r;i++)
//		{
//			if (current)
//			{
//				temp = current;
//			}
//			for (int j = 1;j < c;j++)
//			{
//				temp = temp->right;
//			}
//			current = start;
//			if (start)
//			{
//				start = start->down;
//			}
//		}
//	}
//	void Visited(node* Current)
//	{
//		Current->Print();
//		cout << "-> ";
//	}
//	void EliteNode(node* elite)
//	{
//		if (elite)
//		{
//			cout << "\nElite Node:\n";
//			elite->Print();
//		}
//		else
//		{
//			cout << "\nElite Node Does Not Exsist\n";
//		}
//	}
//	node* FindEliteNode()
//	{
//		node* elite = head;
//		node* temp = 0;
//		bool* array = new bool[rows * cols]();
//		int r = 1;
//		int c = 1;
//		while (true)
//		{
//			Visited(elite);
//			int index = getIndex(r, c);
//			array[index] = 1;
//			r = elite->ClueRow();
//			c = elite->ClueColumn();
//			if (r <= 0 || r > rows || c <= 0 || c > cols)
//			{
//				cout << "\nOut of Bond\n";
//				delete[] array;
//				return 0;
//			}
//			TraverseNode(temp, r, c);
//			if (elite->isElite(temp))
//			{
//				delete[] array;
//				return elite;
//			}
//			if (array[getIndex(r, c)])
//			{
//				delete[] array;
//				cout << "\nNode already visited\n";
//				return 0;
//			}
//			elite = temp;
//		}
//	}
//	~Maze()
//	{
//		node* temp = 0;
//		node* start = head;
//		while (head)
//		{
//			start = start->down;
//			while (head)
//			{
//				temp = head;
//				head = head->right;
//				delete temp;
//				temp = head;
//			}
//			head = start;
//		}
//	}
//};
//void main()
//{
//	string fileName = "task1file.txt";
//	Maze obj;
//	obj.Read(fileName);
//	obj.Print();
//	node* elite = obj.FindEliteNode();
//	obj.EliteNode(elite);
//}