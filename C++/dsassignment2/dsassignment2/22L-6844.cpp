//#include<iostream>
//#include<vector>
//#include<fstream>
//using namespace std;
//class queueNode 
//{
//public:
//	int value;
//	queueNode* nextQueueNode;
//	queueNode()
//	{
//		value = 0;
//		nextQueueNode = 0;
//	}
//	void pushBack(int data)
//	{
//		value = data;
//	}
//	void Print()
//	{
//		cout << value << " ";
//	}
//	~queueNode()
//	{
//		value = 0;
//		nextQueueNode = 0;
//	}
//};
//class myQueue
//{
//public:
//	int size;
//	queueNode* headQueue;
//	myQueue()
//	{
//		headQueue = 0;
//		size = 0;
//	}
//	void pushBack(int data)
//	{
//		size++;
//		if (!headQueue)
//		{
//			headQueue = new queueNode;
//			headQueue->pushBack(data);
//			return;
//		}
//		queueNode* temp = headQueue;
//		while (temp->nextQueueNode)
//		{
//			temp = temp->nextQueueNode;
//		}
//		temp->nextQueueNode = new queueNode;
//		temp->nextQueueNode->pushBack(data);
//	}
//	void Print()
//	{
//		queueNode* temp = headQueue;
//		while (temp)
//		{
//			temp->Print();
//			temp = temp->nextQueueNode;
//		}
//		cout << endl;
//	}
//	int getValue(int index)
//	{
//		if (index >= size)
//		{
//			throw exception("out of bond");
//		}
//		queueNode* temp = headQueue;
//		int i = 0;
//		while (i < index)
//		{
//			temp = temp->nextQueueNode;
//			i++;
//		}
//		return temp->value;
//	}
//	~myQueue()
//	{
//		queueNode* temp = NULL;
//		while (headQueue)
//		{
//			temp = headQueue;
//			headQueue = headQueue->nextQueueNode;
//			delete temp;
//		}
//	}
//};
//template <typename T>
//class stackNode 
//{
//public:
//	T value;
//	stackNode* nextStackNode;
//	stackNode()
//	{
//		value = 0;
//		nextStackNode = 0;
//	}
//	void pushback(T data)
//	{
//		value = data;
//	}
//	int getValue(int index)
//	{
//		return value->getValue(index);
//	}
//	void Print()
//	{
//		value->Print();
//	}
//	~stackNode()
//	{
//		delete value;
//	}
//};
//
//
//class mystack 
//{
//	//utility function for multiplication
//	int CalculateEntry(mystack* mm, int i, int j, int size)
//	{
//		int result = 0;
//		for (int k = 0;k < size;k++)
//		{
//			result = result + getValue(i, k) * mm->getValue(k, j);
//		}
//		return result;
//	}
//	bool CheckExist(mystack* submatrix, int subrow, int subcol,int i,int j)
//	{
//		for (int k = 0;k < subrow;k++)
//		{
//			for (int l = 0;l < subcol;l++)
//			{
//				if (getValue(i + k, j + l) != submatrix->getValue(k, l))
//				{
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//public:
//	stackNode<myQueue*>* stackHead;
//	int size;
//	void pushBack(myQueue* value)
//	{
//		size++;
//		if (!stackHead)
//		{
//			stackHead = new stackNode<myQueue*>;
//			stackHead->pushback(value);
//			return;
//		}
//		auto temp = stackHead;
//		while (temp->nextStackNode)
//		{
//			temp = temp->nextStackNode;
//		}
//		temp->nextStackNode = new stackNode<myQueue*>;
//		temp->nextStackNode->pushback(value);
//	}
//	int getValue(int i, int j)
//	{
//		if (i > size)
//		{
//			throw exception("out of bond");
//		}
//		auto temp = stackHead;
//		int index = 0;
//		while (index < i)
//		{
//			temp = temp->nextStackNode;
//			index++;
//		}
//		return temp->getValue(j);
//	}
//	void addition(mystack* matrix,vector<vector<int>>& result,int& i,int& j,int row,int col)
//	{
//		if (j == col)
//		{
//			i++;
//			j = 0;
//		}
//		//base case
//		if (i == row)
//		{
//			return;
//		}
//		result[i][j] = getValue(i, j) + matrix->getValue(i, j);
//		j++;
//		addition(matrix, result, i, j, row, col);
//	}
//	void subtraction(mystack* matrix, vector<vector<int>>& result, int& i, int& j, int row, int col)
//	{
//		if (j == col)
//		{
//			i++;
//			j = 0;
//		}
//		//base case
//		if (i == row)
//		{
//			return;
//		}
//		result[i][j] = getValue(i, j) - matrix->getValue(i, j);
//		j++;
//		subtraction(matrix, result, i, j, row, col);
//	}
//	void multiplication(mystack* matrix, vector<vector<int>>& result, int& i, int& j, int row, int col,int size)
//	{
//		if (j == col)
//		{
//			i++;
//			j = 0;
//		}
//		//base case
//		if (i >= row)
//		{
//			return;
//		}
//		result[i][j] = CalculateEntry(matrix, i, j, size);
//		j++;
//		multiplication(matrix, result, i, j, row, col,size);
//	}
//	void transpose(vector<vector<int>>& result, int& i, int& j, int row, int col)
//	{
//		if (j >= col)
//		{
//			i++;
//			j = 0;
//		}
//		//base case
//		if (i >= row)
//		{
//			return;
//		}
//		result[j][i] = getValue(i, j);
//		j++;
//		transpose(result, i, j, row, col);
//	}
//	void division(mystack* matrix, vector<vector<int>>& result, int& i, int& j, int row, int col)
//	{
//		if (j == col)
//		{
//			i++;
//			j = 0;
//		}
//		//base case
//		if (i == row)
//		{
//			return;
//		}
//		result[i][j] = getValue(i, j) / matrix->getValue(i, j);
//		j++;
//		division(matrix, result, i, j, row, col);
//	}
//	bool SubMatrix(int row, int col, mystack* submatrix, int subrow, int subcol, int& i, int& j)
//	{
//		if (CheckExist(submatrix, subrow, subcol, i, j))//base case1
//		{
//			return true;
//		}
//		if (j == col)
//		{
//			i++;
//			j = 0;
//		}
//		//base case2
//		if (i >= row)
//		{
//			return false;
//		}
//		j++;
//		SubMatrix(row, col, submatrix, subrow, subcol, i, j);
//	}
//	void Print()
//	{
//		auto temp = stackHead;
//		while (temp)
//		{
//			temp->Print();
//			temp = temp->nextStackNode;
//		}
//	}
//	~mystack()
//	{
//		auto temp = stackHead;
//		while (stackHead)
//		{
//			temp = stackHead;
//			stackHead = stackHead->nextStackNode;
//			delete temp;
//		}
//	}
//};
//
//class Matrix 
//{
//	int row;
//	int col;
//	mystack* headMatrix;
//
//public:
//	Matrix(int r, int c)
//	{
//		row = r;
//		col = c;
//		headMatrix = 0;
//	}
//	Matrix(vector<vector<int>> matrix, int rows, int cols)
//	{
//		row = rows;
//		col = cols;
//		headMatrix = new mystack;
//		for (int i = 0;i < rows;i++)
//		{
//			myQueue* temp = new myQueue;
//			headMatrix->pushBack(temp);
//			for (int j = 0;j < cols;j++)
//			{
//				temp->pushBack(matrix[i][j]);
//			}
//		}
//	}
//	void Print()
//	{
//		headMatrix->Print();
//	}
//	~Matrix()
//	{
//		if (headMatrix)
//		{
//			delete headMatrix;
//		}
//	}
//	Matrix* addition(Matrix* mm)
//	{
//		if (row != mm->row || col != mm->col)
//		{
//			return 0;
//		}
//		vector<vector<int>> result(row,vector<int>(col));
//		int i = 0;
//		int j = 0;
//		headMatrix->addition(mm->headMatrix, result, i, j, row, col);
//		Matrix* res = new Matrix(result, row, col);
//		return res;
//	}
//	Matrix* subtraction(Matrix* mm)
//	{
//		if (row != mm->row || col != mm->col)
//		{
//			return 0;
//		}
//		vector<vector<int>> result(row, vector<int>(col));
//		int i = 0;
//		int j = 0;
//		headMatrix->subtraction(mm->headMatrix, result, i, j, row, col);
//		Matrix* res = new Matrix(result, row, col);
//		return res;
//	}
//	Matrix* multiplication(Matrix* mm)
//	{
//		if (col !=mm->row)
//		{
//			return 0;
//		}
//		vector<vector<int>> result(row, vector<int>(mm->col));
//		int i = 0;
//		int j = 0;
//		headMatrix->multiplication(mm->headMatrix, result, i, j, row, mm->col,col);
//		Matrix* res = new Matrix(result, row, col);
//		return res;
//	}
//	Matrix* division(Matrix* mm)
//	{
//		if (row != mm->row || col != mm->col)
//		{
//			return 0;
//		}
//		vector<vector<int>> result(row, vector<int>(col));
//		int i = 0;
//		int j = 0;
//		headMatrix->division(mm->headMatrix, result, i, j, row, col);
//		Matrix* res = new Matrix(result, row, col);
//		return res;
//	}
//	Matrix* transpose()
//	{
//		vector<vector<int>> result(col, vector<int>(row));
//		int i = 0;
//		int j = 0;
//		headMatrix->transpose(result, i, j, row, col);
//		Matrix* res = new Matrix(result, col, row);
//		return res;
//	}
//	bool isSubMatrix(Matrix* sub)
//	{
//		if (row < sub->row || col < sub->col)
//		{
//			return false;
//		}
//		int r = row - sub->row;
//		int c = col - sub->col;
//		int i = 0;
//		int j = 0;
//		return headMatrix->SubMatrix(r, c, sub->headMatrix, sub->row, sub->col, i, j);
//	}
//};
//
//void main()
//{
//	ifstream file;
//	file.open("data.txt");
//	int row = 0, col = 0;
//	file >> row;
//	file >> col;
//	vector<vector<int>> matrix1(row, vector<int>(col));
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			file >> matrix1[i][j];
//		}
//	}
//	Matrix m1(matrix1, row, col);
//	file >> row;
//	file >> col;
//	vector<vector<int>> matrix2(row, vector<int>(col));
//	for (int i = 0;i < row;i++)
//	{
//		for (int j = 0;j < col;j++)
//		{
//			file >> matrix2[i][j];
//		}
//	}
//	file.close();
//	Matrix m2(matrix2, row, col);
//	cout << "----------------Matrix1------------------\n";
//	m1.Print();
//	cout << endl;
//	cout << "----------------Matrix2------------------\n";
//	m2.Print();
//	cout << endl;
//	cout << "----------------additionMatrix------------------\n";
//	Matrix* result = m1.addition(&m2);
//	if (result)
//	{
//		result->Print();
//		delete result;
//	}
//	cout << "----------------differenceMatrix------------------\n";
//	result = m1.subtraction(&m2);
//	if (result)
//	{
//		result->Print();
//		delete result;
//	}
//	cout << "----------------multiplicationMatrix------------------\n";
//	result = m1.multiplication(&m2);
//	if (result)
//	{
//		result->Print();
//		delete result;
//	}
//	cout << "----------------divisionMatrix------------------\n";
//	result = m1.division(&m2);
//	if (result)
//	{
//		result->Print();
//		delete result;
//	}
//	cout << "----------------transposeMatrix------------------\n";
//	result = m1.transpose();
//	if (result)
//	{
//		result->Print();
//	}
//	delete result;
//	if (m1.isSubMatrix(&m2))
//	{
//		cout << "--------------------SubMatrix exist in Matrix-----------------------";
//	}
//	else
//	{
//		cout << "--------------------SubMatrix !exist in Matrix-----------------------";
//	}
//}