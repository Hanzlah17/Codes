//#include<iostream>
//using namespace std;
//class MemoryBlock
//{
//public:
//	string ID;
//	int TotalBytes;
//	MemoryBlock* nextBlock;
//	MemoryBlock(string id, int totalbytes)
//	{
//		ID = id;
//		TotalBytes = totalbytes;
//		nextBlock = nullptr;
//	}
//	bool AllocateMemory(int bytes, MemoryBlock*& temp)
//	{
//		temp = this;
//		while (temp)
//		{
//			if (bytes < temp->TotalBytes)
//			{
//				temp->ReleaseMemory(bytes);
//				return true;
//			}
//			temp = temp->nextBlock;
//		}
//		cout << "\nMemory Block is not free\n";
//		return false;
//	}
//	void PlaceMemoryBlock(string id, int byte)
//	{
//		MemoryBlock* temp = this;
//		while (temp->nextBlock)
//		{
//			temp = temp->nextBlock;
//		}
//		temp->nextBlock = new MemoryBlock(id, byte);
//	}
//	void DivideMemory(int totalbytes, int parts)
//	{
//		MemoryBlock* temp = this;
//		int quotient = totalbytes / parts;
//		int rem = totalbytes % parts;
//		for (int i = 0;i < parts;i++)
//		{
//			string str;
//			cout << "Enter the ID for this Block";
//			cin >> str;
//			temp->nextBlock = new MemoryBlock(str,quotient);
//			temp = temp->nextBlock;
//		}
//		if (rem)
//		{
//			string str;
//			cout << "Enter the ID for this Block";
//			cin >> str;
//			temp->nextBlock = new MemoryBlock(str, quotient);
//		}
//	}
//	void ReleaseMemory(int bytes)
//	{
//		TotalBytes = TotalBytes - bytes;
//	}
//	~MemoryBlock()
//	{
//		nextBlock = nullptr;
//	}
//};
//class Program
//{
//public:
//	string ID;
//	int Bytes;
//	MemoryBlock* nextBlock;
//	Program* nextProgram;
//	Program(string id,int byte)
//	{
//		ID = id;
//		Bytes = byte;
//		nextBlock = nullptr;
//		nextProgram = nullptr;
//	}
//	void PlaceBlock(string id, int byte)
//	{
//		if (nextBlock)
//		{
//			nextBlock->PlaceMemoryBlock(id, byte);
//		}
//		else
//		{
//			nextBlock = new MemoryBlock(id, byte);
//		}
//	}
//	void ReleaseAllBlocks()
//	{
//		if (nextBlock)
//		{
//			
//		}
//	}
//};
//class RAM
//{
//	MemoryBlock* headBlock;
//	Program* headProgram;
//public:
//	bool GetMemory(string id, int reqbytes)
//	{
//		bool mem = 0;
//		Program* temp = headProgram;
//		Program* current = 0;
//		while (temp&& !mem)
//		{
//			if (temp->ID == id)
//			{
//				mem = 1;
//			}
//			current = temp;
//			temp = temp->nextProgram;
//		}
//		if (!mem)
//		{
//			MemoryBlock* block = 0;
//			if (headBlock)
//			{
//				if (headBlock->AllocateMemory(reqbytes, block))
//				{
//					current->nextProgram = new Program(id, reqbytes);
//					current->nextProgram->nextBlock = new MemoryBlock(block->ID, reqbytes);
//					return true;
//				}
//				return false;
//			}
//		}
//		if (headBlock)
//		{
//			MemoryBlock* block = 0;
//			if (headBlock->AllocateMemory(reqbytes, block))
//			{
//				current->PlaceBlock(block->ID, reqbytes);
//				return true;
//			}
//		}
//		return false;
//	}
//	void DeleteProgram(string id)
//	{
//		Program* temp = 0;
//		if (headProgram->nextProgram)
//		{
//			temp = headProgram->nextProgram;
//			Program* prev = headProgram;
//			while (temp)
//			{
//				if (temp->ID == id)
//				{
//
//				}
//			}
//		}
//	}
//};