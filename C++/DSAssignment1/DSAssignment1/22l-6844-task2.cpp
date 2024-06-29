//#include<iostream>
//#include<fstream>
//using namespace std;
//
////Block class structure
//class Block
//{
//public:
//	string id; // id of block which you will give at start of program
//	int bytes; // bytes of block which you will give at start of program
//	Block* next; // next pointer of block
//	Block* prev;
//
//	Block(string ID, int b)
//	{
//		id = ID;
//		bytes = b;
//		next = 0;
//		prev = 0;
//	}
//	void Print()
//	{
//		cout << "| " << id << " | | " << bytes << " |->";
//	}
//	~Block()
//	{
//		bytes = 0;
//		next = 0;
//		prev = 0;
//	}
//};
//
////PoolNode class structure that Pool class will use
//class PoolNode {
//public:
//	int total_bytes; // total size of pool means sum of bytes of blocks in this pool
//	Block* headOfBlocks; // head pointer of first block
//	Block* tailOfBlocks;
//	PoolNode* nextPoolNode; // next pointer of next pool
//	PoolNode* prevPoolNode;
//
//	PoolNode()
//	{
//		headOfBlocks = tailOfBlocks = 0;
//		nextPoolNode = prevPoolNode = 0;
//		total_bytes = 0;
//
//	}
//	void addBlockAtEnd(string id, int bytes)
//	{
//		Block* nblock = new Block(id, bytes);
//		total_bytes = total_bytes + bytes;
//		if (!headOfBlocks)
//		{
//			headOfBlocks = nblock;
//			tailOfBlocks = nblock;
//			return;
//		}
//		tailOfBlocks->next = nblock;
//		nblock->prev = tailOfBlocks;
//		tailOfBlocks = nblock;
//	}
//	Block* GetBlockByID(string id)
//	{
//		Block* temp = headOfBlocks;
//		while (temp)
//		{
//			if (temp->id == id)
//			{
//				return temp;
//			}
//			temp = temp->next;
//		}
//		return 0;
//	}
//	void  Sort()
//	{
//		Block* temp = headOfBlocks;
//		while (temp)
//		{
//			Block* temp2 = temp->next;
//			while (temp2)
//			{
//				if (temp->bytes > temp2->bytes)
//				{
//					int byte = temp->bytes;
//					string name = temp->id;
//					temp->bytes = temp2->bytes;
//					temp2->bytes = byte;
//					temp->id = temp2->id;
//					temp2->id = name;
//				}
//				temp2 = temp2->next;
//			}
//			temp = temp->next;
//		}
//	}
//	bool Search(int byte, string& id, int strat)
//	{
//		Block* temp = headOfBlocks;
//		if (temp)
//		{
//			if (strat == 1) //best fit
//			{
//				Sort();
//			}
//		}
//		while (temp)
//		{
//			if (temp->bytes >= byte)
//			{
//				id = temp->id;
//				temp->bytes = temp->bytes - byte;
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//	}
//	void Print()
//	{
//		Block* temp = headOfBlocks;
//		while (temp)
//		{
//			temp->Print();
//			temp = temp->next;
//		}
//
//	}
//	~PoolNode()
//	{
//		Block* temp = 0;
//		while (headOfBlocks)
//		{
//			temp = headOfBlocks;
//			headOfBlocks = headOfBlocks->next;
//			delete temp;
//		}
//	}
//};
//
//class Pool
//{
//private:
//	PoolNode* head;
//	PoolNode* tail;
//public:
//	Pool()
//	{
//		head = tail = 0;
//	}
//	void addPoolAtEnd(int numberOfBlocks)
//	{
//		PoolNode* nn = new PoolNode();
//		if (!head)
//		{
//			head = nn;
//			tail = nn;
//		}
//		else
//		{
//			tail->nextPoolNode = nn;
//			nn->prevPoolNode = tail;
//			tail = nn;
//		}
//		ifstream file;
//		file.open("task2file.txt");
//		for (int i = 0; i < numberOfBlocks; i++)
//		{
//			string id;
//			file >> id;
//			int bytes;
//			file >> bytes;
//			tail->addBlockAtEnd(id, bytes);
//		}
//	}
//	Block* GetBlockByID(string id)
//	{
//		PoolNode* temp = head;
//		while (temp)
//		{
//			Block* block = temp->GetBlockByID(id);
//			if (block)
//			{
//				return block;
//			}
//			temp = temp->nextPoolNode;
//		}
//		return 0;
//	}
//	void SortAllPools()
//	{
//		PoolNode* temp = head;
//		while (temp)
//		{
//			temp->Sort();
//			temp = temp->nextPoolNode;
//		}
//	}
//	void Print()
//	{
//		PoolNode* temp = head;
//		int count = 1;
//		while (temp)
//		{
//			cout << "\nPool " << count << endl;
//			temp->Print();
//			count++;
//			temp = temp->nextPoolNode;
//		}
//	}
//	bool Search(int byte, string& id, int strat)
//	{
//		PoolNode* temp = head;
//		while (temp)
//		{
//			if (temp->Search(byte, id, strat))
//			{
//				return true;
//			}
//			temp = temp->nextPoolNode;
//		}
//		return false;
//	}
//	int GiveForceMem(string& id,int size)
//	{
//		PoolNode* temp = head;
//		while (temp)
//		{
//			Block* tem = temp->headOfBlocks;
//			while (tem)
//			{
//				if (tem->bytes)
//				{
//					int byte = tem->bytes;
//					if (size > byte)
//					{
//						tem->bytes = 0;
//					}
//					else
//					{
//						tem->bytes = tem->bytes - size;
//						byte = size;
//					}
//					id = tem->id;
//					return byte;
//				}
//				tem = tem->next;
//			}
//			temp = temp->nextPoolNode;
//		}
//	}
//	bool checkForceAllocation(int bytes)
//	{
//		PoolNode* temp = head;
//		int sum = 0;
//		while (temp)
//		{
//			Block* tem = temp->headOfBlocks;
//			while (tem)
//			{
//				sum += tem->bytes;
//				if (sum >= bytes)
//				{
//					return true;
//				}
//				tem = tem->next;
//			}
//			temp = temp->nextPoolNode;
//		}
//	}
//	~Pool()
//	{
//		PoolNode* temp = 0;
//		while (head)
//		{
//			temp = head;
//			head = head->nextPoolNode;
//			delete temp;
//		}
//	}
//};
//
//class ProgramNode
//{
//public:
//	string name;
//	int sizeOfProgram;
//	Block* headOfBlock;
//	ProgramNode* nextProgramNode;
//	ProgramNode* prevProgramNode;
//	ProgramNode(string n, int size)
//	{
//		name = n;
//		sizeOfProgram = 0;
//		headOfBlock = 0;
//		nextProgramNode = 0;
//		prevProgramNode = 0;
//	}
//	bool Search(string key, ProgramNode*& temp)
//	{
//		temp = this;
//		while (temp)
//		{
//			if (temp->name == key)
//			{
//				return true;
//			}
//			temp = temp->nextProgramNode;
//		}
//		return false;
//	}
//	void Print()
//	{
//		cout << "| " << name << " | | " << sizeOfProgram << " |->";
//		Block* temp = headOfBlock;
//		while (temp)
//		{
//			temp->Print();
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//	void addBlockAtEnd(string id, int bytes)
//	{
//		sizeOfProgram = sizeOfProgram + bytes;
//		if (!headOfBlock)
//		{
//			headOfBlock = new Block(id, bytes);
//			return;
//		}
//		Block* temp = headOfBlock;
//		while (temp->next)
//		{
//			temp = temp->next;
//		}
//		temp->next = new Block(id, bytes);
//		temp->next->prev = temp;
//	}
//	void FreeallBlocks(Pool* pool)
//	{
//		Block* temp = 0;
//		while (headOfBlock)
//		{
//			string blockid = headOfBlock->id;
//			Block* BlockToDelete = pool->GetBlockByID(blockid);
//			if (BlockToDelete)
//			{
//				BlockToDelete->bytes += headOfBlock->bytes;
//			}
//			temp = headOfBlock;
//			headOfBlock = headOfBlock->next;
//			delete temp;
//		}
//		sizeOfProgram = 0;
//
//	}
//	~ProgramNode()
//	{
//		Block* temp = 0;
//		while (headOfBlock)
//		{
//			temp = headOfBlock;
//			headOfBlock = headOfBlock->next;
//			delete temp;
//		}
//	}
//};
//
////Program class structure
//class Program
//{
//private:
//	ProgramNode* head; // head of programs to traverse in programs and their blocks
//	ProgramNode* tail;
//public:
//	Program(string id, int size)
//	{
//		head = 0;
//		tail = 0;
//	}
//	void AddnewProgram(string name, int size, string blockid)
//	{
//		ProgramNode* temp;
//		if (!head)
//		{
//			head = new ProgramNode(name, size);
//			tail = head;
//		}
//		if (!head->Search(name, temp))
//		{
//			temp = new ProgramNode(name, size);
//			tail->nextProgramNode = temp;
//			temp->prevProgramNode = tail;
//			tail = temp;
//		}
//		temp->addBlockAtEnd(blockid, size);
//	}
//	void DeleteProgram(string name,Pool* pool)
//	{
//		if (!head)
//		{
//			cout << "\nNo program is currently running in system\n";
//			return;
//		}
//		ProgramNode* temp;
//		if (head->Search(name,temp))
//		{
//			temp->FreeallBlocks(pool);
//			if (temp == head)
//			{
//				head = head->nextProgramNode;
//				head->prevProgramNode = 0;
//			}
//			if (temp == tail)
//			{
//				tail = tail->prevProgramNode;
//				tail->nextProgramNode = 0;
//			}
//			else
//			{
//				ProgramNode* current = temp->nextProgramNode;
//				temp->prevProgramNode->nextProgramNode = current;
//				current->prevProgramNode = temp->prevProgramNode;
//			}
//			cout << "\nRemoving " << name << " from system\n";
//			delete temp;
//		}
//		else
//		{
//			cout << "\nProgram was not found\n";
//		}
//	}
//	void Print()
//	{
//		ProgramNode* temp = head;
//		while (temp)
//		{
//			temp->Print();
//			temp = temp->nextProgramNode;
//		}
//	}
//	~Program()
//	{
//		ProgramNode* temp = 0;
//		while (head)
//		{
//			temp = head;
//			head = head->nextProgramNode;
//			delete temp;
//		}
//	}
//};
//
//class MemoryManagementSystem
//{
//private:
//	Pool* pools;
//	Program* programs;
//public:
//	void addPool(int bytes)
//	{
//		if (!pools)
//		{
//			pools = new Pool;
//		}
//		pools->addPoolAtEnd(bytes);
//
//	}
//	void addProgram(string name, int size, int strat)
//	{
//		if (!pools)
//		{
//			cout << "Pool does not exist\nProgram cannot be added\n";
//			return;
//		}
//		string id;
//		if (pools->Search(size, id, strat))
//		{
//			if (!programs)
//			{
//				programs = new Program(name, size);
//			}
//			programs->AddnewProgram(name, size, id);
//		}
//		else
//		{
//			cout << "Not Enough space for Program in system\n";
//			cout << "Press 3 if you want to forcefully allocate Memory\n";
//			cin >> strat;
//			if (strat == 3)
//			{
//				if (pools->checkForceAllocation(size))
//				{
//					if (!programs)
//					{
//						programs = new Program(name, size);
//					}
//					while (size > 0)
//					{
//						int byte = pools->GiveForceMem(id,size);
//						size = size - byte;
//						programs->AddnewProgram(name, byte, id);
//					}
//
//				}
//				else
//				{
//					cout << "Program is too big and cannot be even added forcefully\n";
//				}
//				
//			}
//		}
//	}
//	Block*  GetBlockbyId(string key)
//	{
//		if (!pools)
//		{
//			cout << "\nPool does not exist\n";
//			return 0;
//		}
//		return (pools->GetBlockByID(key));
//	}
//	void DeleteProgram(string id)
//	{
//		if (programs)
//		{
//			programs->DeleteProgram(id,pools);
//		}
//	}
//	void PrintProgram()
//	{
//		if (programs)
//		{
//			programs->Print();
//		}
//		else
//		{
//			cout << "\nno program is running currently\n";
//		}
//	}
//	void PrintPool()
//	{
//		if (pools)
//		{
//			pools->Print();
//			cout << endl;
//		}
//		else
//		{
//			cout << "\nPool does not Exit\n";
//		}
//	}
//	~MemoryManagementSystem()
//	{
//		if (programs)
//		{
//			delete programs;
//		}
//		if (pools)
//		{
//			delete pools;
//		}
//	}
//};
//void main()
//{
//	MemoryManagementSystem* system = new MemoryManagementSystem();
//	system->addPool(5);
//	system->PrintPool();
//	system->addProgram("Chess", 60, 1);
//	system->PrintProgram();
//	cout << "\n--------------------------\n";
//	system->addProgram("Ms Word", 200, 1);
//	system->PrintProgram();
//	cout << "\n--------------------------\n";
//	system->addProgram("Chess", 100, 1);
//	/*system->addProgram("temp", 800, 1);
//	system->PrintProgram();
//	cout << "\n--------------------------\n";
//	cout << "\nPool after addition of programs\n";
//	system->PrintPool();
//	system->DeleteProgram("temp");
//	system->PrintProgram();*/
//	cout << "\nPool after deletion of programs\n";
//	system->PrintPool();
//	delete system;
//}