#include<iostream>
#include<fstream>
using namespace std;
int** InputMatrix(ifstream& file, int& rows, int& cols)
{
	file >> rows;
	file >> cols;
	int** matrix = new int* [rows];
	int** end = matrix + rows;
	for (int** i = matrix;i < end;i++)
	{
		*i = new int[cols];
	}
	for (int** i = matrix;i < end;i++)
	{
		int* end1 = *i + cols;
		for (int* j = *i;j < end1;j++)
		{
			file >> *j;
		}
	}
	return matrix;
}
void OutputMatrix(int** matrix, const int rows, const int cols)
{
	int** end = matrix + rows;
	for (int** i = matrix;i < end;i++)
	{
		int* end1 = *i + cols;
		for (int* j = *i;j < end1;j++)
		{
			cout<< *j<<"\t";
		}
		cout << endl;
	}
}
void DeallocateMemory(int** matrix, int& r)
{
	for (int i = 0;i < r;i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}
int** AllocateMemory(int r, int c)
{
	int** matrix = new int* [r];
	int** end = matrix + r;
	for (int** i = matrix;i < end;i++)
	{
		*i = new int[c];
	}
	return matrix;
}
int** AddMatrix(int** matrix1, int** matrix2, const int r1, const int c1, const int r2, const int c2)
{
	int** resultant = 0;
	if (r1 == r2 && c1 == c2)
	{
		resultant = AllocateMemory(r1,c1);
		int** end = resultant + r1;
		int** i1 = matrix1;
		int** i2 = matrix2;
		for (int** i3 = resultant;i3 < end;i1++, i2++, i3++)
		{
			int* end1 = *i3 + c1;
			int* j1 = *i1;
			int* j2 = *i2;
			for (int* j3 = *i3;j3 < end1;j1++, j2++, j3++)
			{
				*j3 = *j1 + *j2;
			}
		}
		return resultant;
	}
	return 0;
}
int** TransposeMatrix(int** matrix, const int& row, const int& col)
{
	int** tra = AllocateMemory(col, row);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			*(*(tra + j) + i) = *(*(matrix + i) + j);
		}
	}
	return tra;
}
bool isEqual(int** matrix1, int** matrix2, const int r, const int c)
{
	bool b = 1;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				b = 0;
			}
		}
	}
	return b;
}
bool isSymmetric(int** matrix, const int& rows, const int& cols)
{
	bool b = 0;
	if (rows == cols)
	{
		int** transpose = TransposeMatrix(matrix, rows, cols);
		if (isEqual(matrix, transpose, rows, cols))
		{
			b = 1;
		}
		int col = cols;
		DeallocateMemory(transpose, col);
	}
	return b;
}
void SwapRows(int*& r1, int*& r2)
{
	int* temp = r1;
	r1 = r2;
	r2 = temp;
}
void InterchangeRows(int** matrix, int row1,int row2)
{
	int r1 = row1;
	int r2 = row2;
	r1--;
	r2--;
	SwapRows((*(matrix + r1)), (*(matrix + r2)));
}
void main()
{
	int rowsA, colsA,rowsB,colsB,rowsC,colsC;
	ifstream file;
	file.open("InputFile.txt");
	int** matrixA = InputMatrix(file, rowsA, colsA);
	int** matrixB= InputMatrix(file, rowsB, colsB);
	int** matrixC= InputMatrix(file, rowsC, colsC);
	file.close();
	cout << "\nMatrixA\n";
	OutputMatrix(matrixA, rowsA, colsA);
	cout << "\nMatrixB\n";
	OutputMatrix(matrixB, rowsB, colsB);
	cout << "\nMatrixC\n";
	OutputMatrix(matrixC, rowsC, colsC);
	int** res = AddMatrix(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
	if (res != 0)
	{
		cout << "\nA + B\n";
		OutputMatrix(res, rowsA, colsA);
		DeallocateMemory(res, rowsA);
	}
	else
	{
		cout << "\nAddition not possible\n";
	}
	res = AddMatrix(matrixB, matrixC, rowsB, colsB, rowsC, colsC);
	if (res != 0)
	{
		cout << "\nB + C\n";
		OutputMatrix(res, rowsB, colsB);
		DeallocateMemory(res, rowsB);
	}
	else
	{
		cout << "\nAddition not possible\n";
	}
	res = AddMatrix(matrixA, matrixC, rowsA, colsA, rowsC, colsC);
	if (res != 0)
	{
		cout << "\nA + C\n";
		OutputMatrix(res, rowsA, colsA);
		DeallocateMemory(res, rowsA);
	}
	else
	{
		cout << "\nAddition not possible\n";
	}
	cout << "\nTranspose of A= \n";
	int** tra = TransposeMatrix(matrixA, rowsA, colsA);
	OutputMatrix(tra, colsA, rowsA);
	DeallocateMemory(tra, colsA);
	cout << "\nTranspose of B= \n";
	tra = TransposeMatrix(matrixB, rowsB, colsB);
	OutputMatrix(tra, colsB, rowsB);
	DeallocateMemory(tra, colsB);
	cout << "\nTranspose of C= \n";
	tra = TransposeMatrix(matrixC, rowsC, colsC);
	OutputMatrix(tra, colsC, rowsC);
	DeallocateMemory(tra, colsC);
	if (isSymmetric(matrixA, rowsA, colsA))
	{
		cout << "\nMatrixA is symmetric\n";
	}
	else
	{
		cout << "\nMatrixA is not symmetric\n";
	}
	if (isSymmetric(matrixB, rowsB, colsB))
	{
		cout << "\nMatrixB is symmetric\n";
	}
	else
	{
		cout << "\nMatrixB is not symmetric\n";
	}
	if (isSymmetric(matrixC, rowsC, colsC))
	{
		cout << "\nMatrixC is symmetric\n";
	}
	else
	{
		cout << "\nMatrixC is not symmetric\n";
	}
	InterchangeRows(matrixC,1,2);
	cout << "\nInterchanged MatrixA\n";
	OutputMatrix(matrixC, rowsC, colsC);
	DeallocateMemory(matrixA, rowsA);
	DeallocateMemory(matrixB, rowsB);
	DeallocateMemory(matrixC, rowsC);

}