#include <iostream>
#include <fstream>
using namespace std;
int** InputMatrix(ifstream& fin, int& rows, int& cols);// Q1 input
void OutputMatrix(int** matrix,  int& ROWS, int& COLS);//Q2 output
int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS);//Q3
int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS);//Q4
bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS);//Q5
void InterchangeRows(int** matrix, const int& row1, const int& row2, const int& COLS);//Q6
void InterchangeRowws(int*& row1, int*& row2);//Q7


int main() {


    ifstream fin("Q1.txt");
    int rows, cols;
    int r = 3;
    int c = 3;


    int** a = new int* [r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            *(*(a + i) + j) = i * j;
        }
    }cout << "Matrix A" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << *(*(a + i) + j) << " ";
        }
        cout << endl;
    }
    int** b = new int* [r];
    for (int i = 0; i < r; i++) {
        b[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            *(*(b + i) + j) = i + j;
        }
    }cout << "Matrix B" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << *(*(b + i) + j) << " ";
        }
        cout << endl;
    }



    int** matrix = InputMatrix(fin, rows, cols);
    cout << " Matrix in file" << endl;
    OutputMatrix(matrix, rows, cols);

    cout << " transpose Matrix in file" << endl;
    int** p = TransposeMatrix(matrix, rows, cols);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << *(*(p + i) + j) << " ";
        }cout << endl;

    }cout << "Symmetric Matrix A " << endl;
    cout << IsSymmetric(matrix, rows, cols);
    cout << endl;

    cout << " Add matrix A And B" << endl;
    int** q = AddMatrix(a, b, 3, 3);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << *(*(q + i) + j) << " ";
        }cout << endl;


        cout << " Interchange Matrix in file" << endl;
        InterchangeRows(matrix, 1, 2, 3);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << *(*(matrix + i) + j) << " ";
            }cout << endl;

            cout << "Interchange matrix in file" << endl;
            InterchangeRowws(matrix[1], matrix[2]);
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cout << *(*(matrix + i) + j) << " ";
                }cout << endl;





                for (int i = 0; i < rows; i++) {
                    delete[] matrix[i];
                }
                delete[] matrix;
                for (int i = 0; i < r; i++) {
                    delete[] a[i];
                }
                delete[] a;
                for (int i = 0; i < r; i++) {
                    delete[] b[i];
                }
                delete[] b;
                system("pause");

                return 0;
            }
        }
    }
}







    int** InputMatrix(ifstream & fin, int& rows, int& cols){
        fin >> rows >> cols;
     int* Data = new int[rows * cols];
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
        matrix[i] = &Data[i * cols];
        }
        
  
        return matrix;
    }





    void OutputMatrix(int** matrix,  int& rows, int& cols)
    {
        ifstream fin("Q1.txt");
       
        fin >> rows >> cols;
   
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fin >> matrix[i][j];
                cout << matrix[i][j] << " ";
            }cout << endl;
        }
  

    
        
    }



    int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS) {
        int** resultMatrix = new int* [ROWS];
        for (int i = 0; i < ROWS; i++) {
            resultMatrix[i] = new int[COLS];
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
        return resultMatrix;
    }

    

    int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS) {
        
        int** transpose = new int* [COLS];
        for (int i = 0; i < COLS; i++) {
            transpose[i] = new int[ROWS];
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                transpose[j][i] = *(*(matrix+i)+j);
            }
        }  

        return transpose;
    }




bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS) {
      
        if (ROWS != COLS) {
            return false;
        }
        int** transpose = new int* [ROWS];
        for (int i = 0; i < ROWS; i++) {
            transpose[i] = new int[COLS];
            for (int j = 0; j < COLS; j++) {
                transpose[i][j] = matrix[j][i];
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (matrix[i][j] != transpose[i][j]) {

                    return false;
                }
            }
        }
        return true;
    }




void InterchangeRows(int** matrix, const int& row1, const int& row2, const int& COLS) {
        for (int j = 0; j < COLS; j++) {
            int temp = matrix[row1][j];
            matrix[row1][j] = matrix[row2][j];
            matrix[row2][j] = temp;
        }
    }





void InterchangeRowws(int*& row1, int*& row2) {
        int* temp = row1;
        row1 = row2;
        row2 = temp;
    }


  
