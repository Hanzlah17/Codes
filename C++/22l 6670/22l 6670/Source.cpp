#include <iostream>
#include <fstream>

using namespace std;

int** AllocateMemory(const int& rows, const int& cols)
{

	int** temp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[rows];
	}
	return  temp;

}

int** InputMatrix(ifstream& fin, int& r, int& c)
{
	fin >> r;
	fin >> c;

	//making of 2d array
	int** array = new int* [r];
	int** last = array + r; //address of last element 
	for (int** temp = array; temp < last; temp++)
	{
		*temp = new int[c];
	}

	for (int** temp = array; temp < last; temp++)
	{
		int* last1 = *temp + c;

		for (int* temp1 = *temp; temp1 < last1; temp1++)
		{
			fin >> *temp1; //takes int from file and stores in array
		}
	}
	return array;

}

void OutputMatrix(int** matrix, int& r, int& c)
{
	int** last = matrix + r;
	for (int** temp = matrix; temp < last; temp++)
	{
		int* end1 = *temp + c;

		for (int* temp1 = *temp; temp1 < end1; temp1++)
		{
			cout << *temp1 << "\t";
		}
		cout << endl;
	}
}

int** AddMatrix(int** matrixA, int** matrixB, const int& r, const int& c, const int& r1, const int& c1)
{
	if (r == r1 && c == c1)
	{
		int** matrixR = AllocateMemory(r, c);  //allocating memory on heap for matrixR
		int** last = matrixR + r;
		int a = 0, b = 0;
		for (int** temp = matrixR; temp < last; temp++)
		{
			int* end1 = *temp + c;
			int* temp1 = *temp;
			while (temp1 < end1)
			{
				*temp1 = *(*(matrixA + a) + b) + *(*(matrixB + a) + b);
				b++;
				temp1++;
			}
			a++;
			b = 0;
		}
		return matrixR;
	}
	return 0;

}

int** TransposeMatrix(int** matrix, const int& r, const int& c)
{
	int** matrixT = AllocateMemory(c, r);

	for (int a = 0; a < r; a++)
	{
		for (int b = 0; b < c; b++)
		{
			*(*(matrixT + b) + a) = *(*(matrix + a) + b);

		}
	}
	return matrixT;
}

bool IsSymmetric(int** matrix, int& rows, int& cols)
{
	int c = 1;
	if (rows == cols)
	{
		int** matrix1 = TransposeMatrix(matrix, rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (*(*(matrix + i) + j) != *(*(matrix1 + i) + j))
				{
					c = 0;
				}
			}
		}
	}
	return c;

}


void SwapRows(int*& row1, int*& row2)
{
	int* temp;
	temp = row1;
	row1 = row2;
	row2 = temp;
}

void InterchangeRows(int** matrix, int row1, int row2)
{
	row1--;
	row2--;
	SwapRows(*(matrix + row1), *(matrix + row2));
}

void DeallocateMemory(int** matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

void main()
{
	ifstream file;
	file.open("InputFile.txt");

	int rowA, colA;
	int rowB, colB;
	int rowC, colC;
	int** A = InputMatrix(file, rowA, colA);
	int** B = InputMatrix(file, rowB, colB);
	int** C = InputMatrix(file, rowC, colC);

	file.close();

	cout << "Matrix A =\n";
	OutputMatrix(A, rowA, colA);
	cout << endl;

	cout << "Matrix B =\n";
	OutputMatrix(B, rowB, colB);
	cout << endl;

	cout << "Matrix C =\n";
	OutputMatrix(C, rowC, colC);
	cout << endl;

	cout << "A + B =\n";
	int** matrixR = 0;
	matrixR = AddMatrix(A, B, rowA, colA, rowB, colB);
	if (matrixR != 0)
	{
		OutputMatrix(matrixR, rowA, colA);
		DeallocateMemory(matrixR, rowA);
	}
	else
		cout << "Addition not possible.\n";

	cout << endl;
	cout << "A + C =\n";
	matrixR = AddMatrix(A, C, rowA, colA, rowC, colC);
	if (matrixR != 0)
	{
		OutputMatrix(matrixR, rowA, colA);
		DeallocateMemory(matrixR, rowA);

	}
	else
		cout << "Addition not possible.\n";


	cout << endl;
	cout << "B + C =\n";
	matrixR = AddMatrix(B, C, rowB, colB, rowC, colC);
	if (matrixR != 0)
	{
		OutputMatrix(matrixR, rowB, colB);
		DeallocateMemory(matrixR, rowB);
	}
	else
		cout << "Addition not possible.\n";

	cout << endl;

	cout << "Transpose of A: \n";
	int** matrixT = TransposeMatrix(A, rowA, colA);
	OutputMatrix(matrixT, colA, rowA);
	DeallocateMemory(matrixT, colA);

	cout << endl;
	cout << "Transpose of C: \n";
	matrixT = TransposeMatrix(C, rowC, colC);
	OutputMatrix(matrixT, colC, rowC);
	DeallocateMemory(matrixT, colC);

	cout << endl;
	if (IsSymmetric(A, rowA, colA))
	{
		cout << "Matrix A is symmetric.";
	}
	else
	{
		cout << "Matrix A is NOT symmetric.";
	}


	

	cout << endl << endl;
	if (IsSymmetric(B, rowB, colB))
	{
		cout << "Matrix B is symmetric.";
	}
	else
	{
		cout << "Matrix B is NOT symmetric.";
	}
	cout << endl;

	if (IsSymmetric(C, rowC, colC))
	{
		cout << "Matrix C is symmetric.";
	}
	else
	{
		cout << "Matrix C is NOT symmetric.";
	}


	cout << endl << endl << "Interchanging Rows of Matrix A:\nrow1: 1 \nrow2 : 3\n";
	cout << "\nAfter Interchanging Rows Matrix A = \n";
	InterchangeRows(C, 1, 2);
	OutputMatrix(C, rowC, colC);

	DeallocateMemory(A, rowA);
	DeallocateMemory(B, rowB);
	DeallocateMemory(C, rowC);
}