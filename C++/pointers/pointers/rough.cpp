//#include<iostream>
//using namespace std;
//int* inputArray(int& size)
//{
//	bool b = 1;
//	int i = 0;
//	int* array = new int[size];
//	while (b == 1)
//	{
//		cout << "Enter the number= ";
//		cin >> array[i];
//		if (array[i] == -1)
//		{
//			b = 0;
//		}
//		i++;
//		if (i == size)
//		{
//			int* temp = new int[size * 2];
//			for (int j = 0;j < size;j++)
//			{
//				temp[j] = array[j];
//			}
//			delete[] array;
//			array = temp;
//			size = size * 2;
//		}
//
//	}
//	return array;
//}
//void main()
//{
//	int size = 5;
//	int* array = inputArray(size);
//	int length = 0;
//	for (int i = 0;array[i] != -1;i++)
//	{
//		length++;
//	}
//	for (int i = 0;i < length;i++)
//	{
//		cout << array[i]<<"\t";
//	}
//	delete array;
//	system("pause");
//}