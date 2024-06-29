#include<iostream>
#include<vector>
using namespace std;
class queueNode
{
public:
	int queueHead;
	queueNode* nextQueueNode;

	queueNode(int val = 0)
	{
		this->queueHead = val;
		nextQueueNode = nullptr;
	}
	void pushBack(int val)
	{
		this->queueHead = val;
	}
	void print()
	{
		cout << queueHead << "\t";
	}
};

class Queue
{
public:
	queueNode* front;
	queueNode* rear;
	Queue()
	{
		front = rear = nullptr;
	}

	void enQueue(int x)
	{
		if (!front)
		{
			front = new queueNode;
			front->pushBack(x);
			return;
		}
		queueNode* temp = front;
		queueNode* nn = new queueNode;
		nn->pushBack(x);
		while (temp->nextQueueNode)
		{
			temp = temp->nextQueueNode;
		}
		temp->nextQueueNode = nn;
	}

	void deQueue()
	{
		if (front == nullptr)
		{
			return;
		}

		queueNode* temp = front;
		front = front->nextQueueNode;

		if (front == nullptr)
		{
			rear = nullptr;
		}

		delete (temp);
	}
	void print()
	{
		queueNode* temp = front;
		while (temp)
		{
			cout << temp->queueHead << "\t";
			temp = temp->nextQueueNode;
		}
		cout << endl;
	}
};

template <typename T>
class stackNode
{
public:
	queueNode* queueHead;
	stackNode* nextStackNode;

	stackNode()
	{
		nextStackNode = nullptr;
		queueHead = nullptr;
	}
	stackNode(queueNode* val)
	{
		queueHead = val;
		nextStackNode = nullptr;
	}
	void print()
	{
		queueNode* temp = queueHead;
		while (temp)
		{
			temp->print();
			temp = temp->nextQueueNode;
		}

	}
};

class stack
{
public:
	stackNode<queueNode>* stackHead;
	int count;

	stack()
	{
		count = 0;
		stackHead = nullptr;
	}
	void pushBack(queueNode* queueHead)
	{
		count++;
		if (!stackHead)
		{
			stackHead = new stackNode<queueNode>(queueHead);
			return;
		}
		stackNode<queueNode>* temp = stackHead;
		stackNode<queueNode>* nn = new stackNode<queueNode>(queueHead);
		while (temp->nextStackNode)
		{
			temp = temp->nextStackNode;
		}
		temp->nextStackNode = nn;
	}
	void print()
	{
		stackNode<queueNode>* temp = stackHead;
		while (temp)
		{
			temp->print();
			temp = temp->nextStackNode;
			cout << endl;
		}

	}

	vector<vector<int>> matrixToVector(int r, int c)
	{
		int i = 0, j = 0;
		vector<vector<int>> vect(r, vector<int>(c));
		for (stackNode<queueNode>* stacktemp = stackHead; stacktemp != nullptr; stacktemp = stacktemp->nextStackNode)
		{
			j = 0;
			for (queueNode* queuetemp = stacktemp->queueHead; queuetemp != nullptr; queuetemp = queuetemp->nextQueueNode)
			{
				vect[i][j] = queuetemp->queueHead;
				j++;
			}
			i++;
		}
		return vect;
	}


	void reverseStack()
	{
		for (int i = 0; i < count; i++)
		{

		}
	}

	void addition(vector<vector<int>>& result, vector<vector<int>>& v1, vector<vector<int>>& v2, int& i, int& j, int row, int col)
	{
		if (j == col)
		{
			i++;
			j = 0;
		}
		if (i == row)
		{
			return;
		}
		result[i][j] = v1[i][j] + v2[i][j];
		j++;
		addition(result, v1, v2, i, j, row, col);
	}

	void subtraction(vector<vector<int>>& result, vector<vector<int>>& v1, vector<vector<int>>& v2, int& i, int& j, int row, int col)
	{
		if (j == col)
		{
			i++;
			j = 0;
		}

		if (i == row)
		{
			return;
		}
		result[i][j] = v1[i][j] - v2[i][j];
		j++;
		subtraction(result, v1, v2, i, j, row, col);
	}

	void multiplication(vector<vector<int>>& result, vector<vector<int>>& v1, vector<vector<int>>& v2, int& i, int& j, int row, int col, int s)
	{
		if (j == col)
		{
			i++;
			j = 0;
		}

		if (i == row)
		{
			return;
		}
		for (int k = 0; k < s; k++)
		{
			result[i][j] += v1[i][k] * v2[k][j];
		}

		j++;
		multiplication(result, v1, v2, i, j, row, col, s);
	}

	void division(vector<vector<int>>& result, vector<vector<int>>& v1, vector<vector<int>>& v2, int& i, int& j, int row, int col)
	{
		if (j == col)
		{
			i++;
			j = 0;
		}

		if (i == row)
		{
			return;
		}
		result[i][j] = v1[i][j] / v2[i][j];
		j++;
		division(result, v1, v2, i, j, row, col);
	}

	void transpose(vector<vector<int>>& result, vector<vector<int>>& v1, int& i, int& j, int row, int col)
	{
		if (j >= col)
		{
			i++;
			j = 0;
		}
		if (i >= row)
		{
			return;
		}
		result[j][i] = v1[i][j];
		j++;
		transpose(result, v1, i, j, row, col);
	}

	bool SubMatrix(vector<vector<int>>& v1, vector<vector<int>>& v2, int row, int col, int subrow, int subcol, int& i, int& j)
	{
		bool b = 1;
		for (int k = 0; k < subrow; k++)
		{
			for (int l = 0; l < subcol; l++)
			{
				if (v1[i + k][j + l] != v2[k][l])
				{
					b = 0;
				}
			}
		}

		if (b == 1)
		{
			return true;
		}
		if (j == col)
		{
			i++;
			j = 0;
		}
		if (i >= row)
		{
			return false;
		}
		j++;
		SubMatrix(v1, v2, row, col, subrow, subcol, i, j);
	}
};



class Matrix
{
public:
	stack* matrixHead;
	int row;
	int col;

	stack* getMatrixHead()
	{
		return matrixHead;
	}

	Matrix()
	{
		matrixHead = nullptr;
		row = col = 0;
	}
	void vectorToMatrix(vector<vector<int>> res, int rows, int cols)
	{
		row = rows;
		col = cols;
		matrixHead = new stack;
		for (int i = 0; i < rows; i++)
		{
			Queue obj;
			for (int j = 0; j < cols; j++)
			{
				obj.enQueue(res[i][j]);
			}
			queueNode* temp = obj.front;
			matrixHead->pushBack(temp);
		}
	}

	void print()
	{
		matrixHead->print();
		cout << endl;
	}

	vector<vector<int>> getMatrix()
	{
		return matrixHead->matrixToVector(row, col);
	}

	Matrix* addition(Matrix* mm)
	{
		if (row != mm->row || col != mm->col)
		{
			return 0;
		}
		vector<vector<int>> result(row, vector<int>(col));

		vector<vector<int>> m1(row, vector<int>(col));
		m1 = getMatrix();
		vector<vector<int>> m2(row, vector<int>(col));
		m2 = mm->getMatrix();

		int i = 0, j = 0;
		matrixHead->addition(result, m1, m2, i, j, row, col);
		Matrix* tempMatrix = new Matrix();
		tempMatrix->vectorToMatrix(result, row, col);
		return tempMatrix;
	}

	Matrix* subtraction(Matrix* mm)
	{
		if (row != mm->row || col != mm->col)
		{
			return 0;
		}
		vector<vector<int>> result(row, vector<int>(col));

		vector<vector<int>> m1(row, vector<int>(col));
		m1 = getMatrix();
		vector<vector<int>> m2(row, vector<int>(col));
		m2 = mm->getMatrix();

		int i = 0, j = 0;
		matrixHead->subtraction(result, m1, m2, i, j, row, col);
		Matrix* tempMatrix = new Matrix();
		tempMatrix->vectorToMatrix(result, row, col);
		return tempMatrix;
	}

	Matrix* multiplication(Matrix* mm)
	{
		if (col != mm->row)
		{
			return 0;
		}
		vector<vector<int>> result(mm->col, vector<int>(row));

		vector<vector<int>> m1(row, vector<int>(col));
		m1 = getMatrix();
		vector<vector<int>> m2(row, vector<int>(col));
		m2 = mm->getMatrix();

		int i = 0, j = 0;
		matrixHead->multiplication(result, m1, m2, i, j, row, mm->col, col);
		Matrix* tempMatrix = new Matrix();
		tempMatrix->vectorToMatrix(result, mm->col, row);
		return tempMatrix;
	}

	Matrix* division(Matrix* mm)
	{
		if (row != mm->row || col != mm->col)
		{
			return 0;
		}
		vector<vector<int>> result(row, vector<int>(col));

		vector<vector<int>> m1(row, vector<int>(col));
		m1 = getMatrix();
		vector<vector<int>> m2(row, vector<int>(col));
		m2 = mm->getMatrix();

		int i = 0;
		int j = 0;
		matrixHead->division(result, m1, m2, i, j, row, col);
		Matrix* tempMatrix = new Matrix();
		tempMatrix->vectorToMatrix(result, row, col);
		return tempMatrix;
	}

	Matrix* transpose()
	{
		vector<vector<int>> result(col, vector<int>(row));
		vector<vector<int>> m1(row, vector<int>(col));
		m1 = getMatrix();
		int i = 0;
		int j = 0;
		matrixHead->transpose(result, m1, i, j, row, col);
		Matrix* tempMatrix = new Matrix();
		tempMatrix->vectorToMatrix(result, col, row);
		return tempMatrix;

	}

	bool isSubMatrix(Matrix* mm)
	{
		if (row < mm->row || col < mm->col)
		{
			return false;
		}
		vector<vector<int>> m1(row, vector<int>(col));
		m1 = getMatrix();

		vector<vector<int>> m2(row, vector<int>(col));
		m2 = mm->getMatrix();


		int r = row - mm->row;
		int c = col - mm->col;
		int i = 0, j = 0;
		return matrixHead->SubMatrix(m1, m2, row, col, r, c, i, j);
	}
	~Matrix()
	{
		if (matrixHead)
		{
			delete matrixHead;
		}
	}
};

int main()
{
	int r, c;
	cout << "Enter rows: ";
	cin >> r;
	cout << "Enter columns: ";
	cin >> c;
	vector<vector<int>> vect(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "Enter value: ";
			cin >> vect[i][j];
		}
	}

	int r1, c1;
	cout << "Enter rows: ";
	cin >> r1;
	cout << "Enter columns: ";
	cin >> c1;
	vector<vector<int>> vect1(r1, vector<int>(c1));
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			cout << "Enter value: ";
			cin >> vect1[i][j];
		}
	}
	cout << endl;
	Matrix m1;
	Matrix m2;
	m1.vectorToMatrix(vect, r, c);
	cout << "~ Matrix 1 ~\n";
	m1.print();
	m2.vectorToMatrix(vect1, r1, c1);
	cout << "~ Matrix 2 ~\n";
	m2.print();
	Matrix* temp;

	if (r == r1 && c == c1)
	{

		cout << "~ Addition ~\n";
		temp = m1.addition(&m2);
		temp->print();
		delete temp;
		cout << "~ Subtraction ~\n";
		temp = m1.subtraction(&m2);
		temp->print();
		delete temp;
		cout << "~ Division ~\n";
		temp = m1.division(&m2);
		temp->print();
		delete temp;

	}
	else
	{
		cout << "Operations not possible, matrices are not equal.\n";
	}

	if (c == r1)
	{
		cout << "~ Multiplication ~\n";
		temp = m1.multiplication(&m2);
		temp->print();
	}
	else
	{
		cout << "Matrix multiplication not possible.\n";
	}

	cout << "~ Transpose of m1 ~\n";
	temp = m1.transpose();
	temp->print();
	delete temp;

	cout << "~ Transpose of m2 ~\n";
	temp = m2.transpose();
	temp->print();

	if (m1.isSubMatrix(&m2))
	{
		cout << "m2 is a sub-matrix of m1\n";
	}
	else
	{
		cout << "m2 is not a sub-matrix of m1\n";
	}
}