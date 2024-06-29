#include<iostream>
#include<fstream>
using namespace std;
int StringLength(char* str)
{
	int c = 0;
	for (int i = 0;str[i] != '\0';i++)
	{
		c++;
	}
	return c;
}
char* Input()
{
	char temp[100];
	cout << "\nEnter the sentence:";
	cin.getline(temp, 100);
	int size = StringLength(temp);
	size++;
	char* input = new char[size];
	int i = 0;
	while (temp[i] != '\0')
	{
		input[i] = temp[i];
		i++;
	}
	input[i] = '\0';
	return input;
}
void StringCopy(char* s, char* d)
{
	int i = 0;
	for (i = 0;s[i] != '\0';i++)
	{
		d[i] = s[i];
	}
	d[i] = '\0';
}
void WordCopy(char* s, char* d,int& j)
{
	int i = 0;
	for (i=0;s[j] != '\0'&& s[j] != ' ';i++,j++)
	{
		d[i] = s[j];
	}
	d[i] = '\0';
	j++;
}
void Swap(char*& a, char*& b)
{
	char* temp = a;
	a = b;
	b = temp;
}
void StringConcatenate(char*& str1, char* str2)
{
	int l1 = StringLength(str1);
	int l2 = StringLength(str2);
	int size = l1 + l2;
	size = size + 2;
	char* temp = new char[size];
	int k = 0,i=0;
	for (int i = 0;str1[i] != '\0';i++)
	{
		temp[k] = str1[i];
		k++;
	}
	temp[k] = ' ';
	k++;
	for (int i = 0;str2[i] != '\0';i++)
	{
		temp[k] = str2[i];
		k++;
	}
	temp[k] = '\0';
	delete[] str1;
	str1 = temp;
}
int WordCount(char* str)
{
	int c = 0;
	for (int i = 0;str[i] != '\0';i++)
	{
		if (str[i] == ' ')
		{
			c++;
		}
	}
	c++;
	return c;
}
char** StringTokens(char* str)
{
	int j = 0;
	char temp[50];
	int rows = WordCount(str);
	char** Stringtokens = new char* [rows];
	for (int i = 0;i < rows;i++)
	{
		WordCopy(str, temp,j);
		int l = StringLength(temp);
		Stringtokens[i] = new char[l + 1];
		StringCopy(temp, Stringtokens[i]);
	}
	return Stringtokens;
}
void Print(char** Stringt, int rows)
{
	for (int i = 0;i < rows;i++)
	{
		cout << Stringt[i];
		cout << "\n";
	}
}
void DeAllocate(char** Stringt, int r)
{
	for (int i = 0;i < r;i++)
	{
		delete[] Stringt[i];
	}
	delete[] Stringt;
}
char** InverseStringTokens(char* str)
{
	char** string = StringTokens(str);
	int r = WordCount(str);
	r--;
	int i = 0, j =r ;
	while (i < j)
	{
		Swap(string[i], string[j]);
		i++;
		j--;
	}
	return string;
}
char* ReverseSentence(char* str)
{
	int l = StringLength(str);
	l++;
	char* revstr = new char[l];
	revstr[0] = '\0';
	char** string = InverseStringTokens(str);
	int r = WordCount(str);
	for (int i = 0;i < r;i++)
	{
		StringConcatenate(revstr, string[i]);
	}
	DeAllocate(string, r);
	return revstr;
}
void toLower(char& a)
{
	if (a >= 65 && a <= 90)
	{
		a = a + 32;
	}
}
int CompareChar(char a, char b)
{
	toLower(a);
	toLower(b);
	if (a < b)
	{
		return -1;
	}
	else if (a > b)
	{
		return 1;
	}
	return 0;
}
int CompareString(char* str1, char* str2)
{
	int b = 0;
	for (int i = 0;str1[i] != '\0' && str2[i] != '\0' && b == 0;i++)
	{
		b = CompareChar(str1[i], str2[i]);
	}
	if (b == 0 && (StringLength(str1) < StringLength(str2)))
	{
		b = -1;
	}
	else if (b == 0 && (StringLength(str1) > StringLength(str2)))
	{
		b = 1;
	}
	return b;
}
char** ReadStudentslistfromfile(ifstream& file, int& size)
{
	char temp[50];

	size = 82;
	char** list = new char* [size];
	for (int i = 0; i < size; i++)
	{
		file.getline(temp, 50);
		int c = StringLength(temp);
		list[i] = new char[c + 1];
		StringCopy(temp, list[i]);
	}
	return list;
}
void Sortlist(char** list,int& size)
{
	for (int i = 0;i < size;i++)
	{
		for (int j = i;j < size;j++)
		{
			if (CompareString(list[j], list[i]) == -1)
			{
				Swap(list[i], list[j]);
			}
		}
	}
}
char** StudentListF(ifstream& file, int& size)
{
	char** list = ReadStudentslistfromfile(file, size);
	cout << "\n----------------Before Sorting List---------------- \n";
	Print(list, size);
	Sortlist(list, size);
	cout << "\n----------------After Sorting List---------------- \n";
	Print(list, size);
	return list;
}
int main()
{
	char* str1 = Input();
	char* str2 = Input();
	cout << "-----Answer1----------\n";
	cout << "\nBefore: \n";
	cout << "String1: \n" << str1 << endl;
	cout << "String2: \n" << str2 << endl;
	StringConcatenate(str1, str2);
	cout << "\nAfter: \n";
	cout << "String1: \n" << str1 << endl;
	cout << "String2: \n" << str2 << endl;
	delete[] str1;
	delete[] str2;
	cout << "\n-----Answer2----------\n";
	char* str = Input();
	char** Stringt = StringTokens(str);
	int r = WordCount(str);
	Print(Stringt, r);
	cout << endl;
	cout << "\n-----Answer3----------\n";
	char** InverStringt = InverseStringTokens(str);
	Print(InverStringt, r);
	DeAllocate(Stringt, r);
	DeAllocate(InverStringt, r);
	cout << "\n-----Answer4----------\n";
	char* rstr = ReverseSentence(str);
	cout << rstr;
	delete[] str;
	delete[] rstr;
	cout << "\n-----Answer5----------\n";
	ifstream file;
	int size;
	file.open("StudentList.txt");
	char** list = StudentListF(file, size);
	DeAllocate(list, size);
	file.close();
}
