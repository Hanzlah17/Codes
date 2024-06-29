#include<iostream>
using namespace std;
template <class T>
class Matrix
{
private:
	T** matrix;
	int rows;
	int cols;

	//utility function
	void allocate()
	{
		matrix = new T* [rows];
		for (int i = 0;i < rows;i++)
		{
			matrix[i] = new T[cols];
		}
	}
	void Deallocate()
	{
		for (int i = 0;i < rows;i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

public:
	Matrix(int r=0,int c=0)
	{
		rows = r;
		cols = c;
		if (r && c)
		{
			allocate();
		}
		else
		{
			matrix = 0;
		}
	}
	void Print()
	{
		if (matrix)
		{
			for (int i = 0;i < rows;i++)
			{
				for (int j = 0;j < cols;j++)
				{
					cout << matrix[i][j] << " ";
				}
				cout << "\n";
			}
		}
	}
	void Input()
	{
		if (matrix)
		{
			for (int i = 0;i < rows;i++)
			{
				for (int j = 0;j < cols;j++)
				{
					cin>> matrix[i][j];
				}
			}
		}
		else
		{
			cout << "Enter the rows of matrix= ";
			cin >> rows;
			while (rows < 1)
			{
				cout << "\nEnter valid number for rows!!\n";
				cout << "Enter the rows of matrix= ";
				cin >> rows;
			}
			cout << "Enter the columns of matrix= ";
			cin >> cols;
			while (cols < 1)
			{
				cout << "\nEnter valid number for columns!!\n";
				cout << "Enter the columns of matrix= ";
				cin >> cols;
			}
			allocate();
			for (int i = 0;i < rows;i++)
			{
				for (int j = 0;j < cols;j++)
				{
					cin >> matrix[i][j];
				}
			}
		}
	}
	Matrix& operator=(const Matrix& a)
	{
		if (this != &a)
		{
			if (matrix)
			{
				Deallocate();
			}
			rows = a.rows;
			cols = a.cols;
			allocate();
			for (int i = 0;i < rows;i++)
			{
				for (int j = 0;j < cols;j++)
				{
					matrix[i][j] = a.matrix[i][j];
				}
			}
		}
		return *this;
	}
	void MultiplyMatrix(Matrix& temp)
	{
		Matrix res;
		res = temp;
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < cols;j++)
			{
				T sum = 0;
				for (int k = 0;k < cols;k++)
				{
					sum = matrix[i][k] * res.matrix[k][j] + sum;
				}
				temp.matrix[i][j] = sum;
			}
		}
	}
	void Exponent(int exp)
	{
		if (exp >= 0)
		{
			Matrix temp;
			temp = *this;
			for (int i = 1;i < exp;i++)
			{
				MultiplyMatrix(temp);
			}
			*this = temp;
		}
	}
	~Matrix()
	{
		if (matrix)
		{
			Deallocate();
		}
	}
};
void main()
{
	Matrix<char> a;
	a.Input();
	a.Print();
	a.Exponent(2);
	a.Print();
}