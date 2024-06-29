//#include<iostream>
//#include<fstream>
//using namespace std;
//int StringLength(char* str)
//{
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//void Copy(char*& des,char* sor)
//{
//	int i;
//	if (des == 0)
//	{
//		i = StringLength(sor);
//		des = new char[i + 1];
//	}
//	i = 0;
//	while (sor[i] != '\0')
//	{
//		des[i] = sor[i];
//		i++;
//	}
//	des[i] = '\0';
//}
//void Copy(int*& des, int* sor, int s)
//{
//	if (des == 0)
//	{
//		des = new int[s];
//	}
//	for (int i = 0;i < s;i++)
//	{
//		des[i] = sor[i];
//	}
//}
//void GetMarks(ifstream& file, int* temp,int total)
//{
//	for (int i = 0;i < total;i++)
//	{
//		int a = 0;
//		file >> a;
//		temp[i] = a;
//	}
//}
//int Sum(int* temp,int s)
//{
//	int sum = 0;
//	for (int i = 0;i < s;i++)
//	{
//		sum = sum + temp[i];
//	}
//	return sum;
//}
//bool IsExist(char* str, char* sub)
//{
//	bool b = 0;
//	bool b1 = 1;
//	int k = 0;
//	for (int i = 0;str[i] != '\0'&& b1==1;i++)
//	{
//		if (str[i] == sub[k])
//		{
//			b = 1;
//			int j = i+1;
//			k = 1;
//			while (str[j] != '\0' && sub[k]!='\0')
//			{
//				if (str[j] != sub[k])
//				{
//					b = 0;
//				}
//				j++;
//				k++;
//			}
//			if (b == 1)
//			{
//				b1 = 0;
//			}
//		}
//	}
//	return b;
//}
//
//
//class EvalReport
//{
//	friend ostream& operator<<(ostream&, const EvalReport&);
//	friend void PrintAll(EvalReport*, int);
//	friend void SortListByTotal(EvalReport*);
//private:
//	static int TotalStudents;
//	static int TotalQuiz;
//	static int TotalAssignment;
//	static int* TotalMarksQuiz;
//	static int* TotalMarksAssignment;
//	char* RollNumber;
//	char* Name;
//	int* quiz;
//	int* assignment;
//	int total;
//	static int* minimumQ;
//	static int* maximumQ;
//	static int* AverageQ;
//	static  int* minimumA;
//	static int* maximumA;
//	static int* AverageA;
//public:
//	static void SetStaticData(ifstream&);
//	static void DeleteStaticData();
//	EvalReport()
// 	{
//		RollNumber = 0;
//		Name = 0;
//		quiz = 0;
//		assignment =0;
//		total = 0;
//	}
//	~EvalReport()
//	{
//		delete[] RollNumber;
//		delete[] Name;
//		delete[] quiz;
//		delete[] assignment;
//	}
//	EvalReport& operator=(const EvalReport& a)
//	{
//		if (&a != this)
//		{
//			RollNumber = new char[StringLength(a.RollNumber) + 1];
//			Copy(RollNumber, a.RollNumber);
//			Name= new char[StringLength(a.Name) + 1];
//			Copy(Name, a.Name);
//			quiz = new int[TotalQuiz];
//			Copy(quiz, a.quiz, TotalQuiz);
//			assignment = new int[TotalAssignment];
//			Copy(assignment, a.assignment, TotalAssignment);
//			total = a.total;
//		}
//		return *this;
//	}
//	void SetRollNumber(char* temp)
//	{
//		Copy(RollNumber, temp);
//	}
//	void SetName(char* temp)
//	{
//		Copy(Name, temp);
//	}
//	void SetQuiz(int* temp)
//	{
//		Copy(quiz, temp, TotalQuiz);
//	}
//	void SetAssignment(int* temp)
//	{
//		Copy(assignment, temp, TotalAssignment);
//	}
//	EvalReport(const EvalReport& a)
//	{
//		RollNumber = new char[StringLength(a.RollNumber) + 1];
//		Copy(RollNumber, a.RollNumber);
//		Name = new char[StringLength(a.Name) + 1];
//		Copy(Name, a.Name);
//		quiz = new int[TotalQuiz];
//		Copy(quiz, a.quiz, TotalQuiz);
//		assignment = new int[TotalAssignment];
//		Copy(assignment, a.assignment, TotalAssignment);
//		total = a.total;
//	}
//	static int GetTotalStudents()
//	{
//		return TotalStudents;
//	}
//	static int GetTotalQuiz()
//	{
//		return TotalQuiz;
//	}
//	static int GetTotalAssignment()
//	{
//		return TotalAssignment;
//	}
//	static void SetMinimumQ(EvalReport* list)
//	{
//		int size = EvalReport::GetTotalStudents();
//		int total = EvalReport::GetTotalQuiz();
//		for (int i = 0;i < total;i++)
//		{
//			minimumQ[i] = 0;
//			for (int j = 0;j < size;j++)
//			{
//				int a = list[j].quiz[i];
//				if (minimumQ[i] > a)
//				{
//					minimumQ[i] = a;
//				}
//			}
//		}
//	}
//	static void SetMaximumQ(EvalReport* list)
//	{
//		int size = EvalReport::GetTotalStudents();
//		int total = EvalReport::GetTotalQuiz();
//		for (int i = 0;i < total;i++)
//		{
//			maximumQ[i] = 0;
//			for (int j = 0;j < size;j++)
//			{
//				int a = list[j].quiz[i];
//				if (maximumQ[i] < a)
//				{
//					maximumQ[i] = a;
//				}
//			}
//		}
//	}
//	static void SetAverageQ(EvalReport* list)
//	{
//		int size = EvalReport::GetTotalStudents();
//		int total = EvalReport::GetTotalQuiz();
//		for (int i = 0;i < total;i++)
//		{
//			int sum = 0;
//			for (int j = 0;j < size;j++)
//			{
//				sum = sum + list[j].quiz[i];
//			}
//			AverageQ[i] = sum / size;
//		}
//	}
//
//
//	static void SetMinimumA(EvalReport* list)
//	{
//		int size = EvalReport::GetTotalStudents();
//		int total = EvalReport::GetTotalAssignment();
//		for (int i = 0;i < total;i++)
//		{
//			minimumA[i] = 0;
//			for (int j = 0;j < size;j++)
//			{
//				int a = list[j].assignment[i];
//				if (minimumA[i] > a)
//				{
//					minimumA[i] = a;
//				}
//			}
//		}
//	}
//	static void SetMaximumA(EvalReport* list)
//	{
//		int size = EvalReport::GetTotalStudents();
//		int total = EvalReport::GetTotalAssignment();
//		for (int i = 0;i < total;i++)
//		{
//			maximumA[i] = 0;
//			for (int j = 0;j < size;j++)
//			{
//				int a = list[j].assignment[i];
//				if (maximumA[i] < a)
//				{
//					maximumA[i] = a;
//				}
//			}
//		}
//	}
//	static void SetAverageA(EvalReport* list)
//	{
//		int size = EvalReport::GetTotalStudents();
//		int total = EvalReport::GetTotalAssignment();
//		for (int i = 0;i < total;i++)
//		{
//			int sum = 0;
//			for (int j = 0;j < size;j++)
//			{
//				sum = sum + list[j].assignment[i];
//			}
//			AverageA[i] = sum / size;
//		}
//	}
//	void SetTotal()
//	{
//		total = Sum(quiz, TotalQuiz) + Sum(assignment, TotalAssignment);
//	}
//	static void UpdateStatistics(EvalReport* list)
//	{
//		EvalReport::SetMinimumQ(list);
//		EvalReport::SetMaximumQ(list);
//		EvalReport::SetAverageQ(list);
//
//		EvalReport::SetMinimumA(list);
//		EvalReport::SetMaximumA(list);
//		EvalReport::SetAverageA(list);
//
//	}
//	static void PrintStatistics()
//	{
//		int s = GetTotalQuiz();
//		cout << "Total:\t\t";
//		for (int i = 0;i < s;i++)
//		{
//			cout << TotalMarksQuiz[i]<<"\t";
//		}
//		int s1 = GetTotalAssignment();
//		for (int i = 0;i < s1;i++)
//		{
//			cout << TotalMarksAssignment[i] << "\t";
//		}
//		cout << "\nMaximum:\t";
//		for (int i = 0;i < s;i++)
//		{
//			cout << maximumQ[i] << "\t";
//		}
//		for (int i = 0;i < s1;i++)
//		{
//			cout << maximumA[i] << "\t";
//		}
//		cout << "\nMinimum:\t";
//		for (int i = 0;i < s;i++)
//		{
//			cout << minimumQ[i] << "\t";
//		}
//		for (int i = 0;i < s1;i++)
//		{
//			cout << minimumA[i] << "\t";
//		}
//		cout << "\nAverage:\t";
//		for (int i = 0;i < s;i++)
//		{
//			cout << AverageQ[i] << "\t";
//		}
//		for (int i = 0;i < s1;i++)
//		{
//			cout << AverageA[i] << "\t";
//		}
//	}
//	static EvalReport* SearchStudentsByKeyWord(EvalReport* list,char* str,int& count)
//	{
//		int size = EvalReport::GetTotalStudents();
//		count = 0;
//		for (int i = 0; i < size; i++)
//		{
//			if (IsExist(list[i].RollNumber, str) || IsExist(list[i].Name, str)) 
//			{
//				count++;
//			}
//		}
//		if (count > 0)
//		{
//			EvalReport* temp = new EvalReport[count];
//			int j = 0;
//			for (int i = 0; i < size; i++) {
//				if (IsExist(list[i].RollNumber, str) || IsExist(list[i].Name, str))
//				{
//					temp[j] = list[i];
//					j++;
//				}
//			}
//			return temp;
//		}
//		return 0;
//	}
//};
//
//
////initializing static data
//int EvalReport::TotalStudents = 0;
//int EvalReport::TotalQuiz = 0;
//int EvalReport::TotalAssignment = 0;
//int* EvalReport::TotalMarksQuiz = 0;
//int* EvalReport::TotalMarksAssignment = 0;
//int* EvalReport::minimumQ = 0;
//int* EvalReport::maximumQ = 0;
//int* EvalReport::AverageQ = 0;
//int* EvalReport::minimumA = 0;
//int* EvalReport::maximumA = 0;
//int* EvalReport::AverageA = 0;
////reading static data from start of file
//void EvalReport:: SetStaticData(ifstream& file)
//{
//	int a = 0;
//	file >> a;
//	EvalReport::TotalStudents = a;
//	file >> a;
//	EvalReport::TotalQuiz = a;
//	file >> a;
//	EvalReport::TotalAssignment = a;
//	EvalReport::TotalMarksQuiz = new int[TotalQuiz];
//	EvalReport::TotalMarksAssignment = new int[TotalAssignment];
//
//	EvalReport::minimumQ = new int[TotalQuiz];
//	EvalReport::maximumQ = new int[TotalQuiz];
//	EvalReport::AverageQ = new int[TotalQuiz];
//
//	EvalReport::minimumA = new int[TotalAssignment];
//	EvalReport::maximumA = new int[TotalAssignment];
//	EvalReport::AverageA = new int[TotalAssignment];
//	for (int i = 0;i < TotalQuiz;i++)
//	{
//		int a = 0;
//		file >> a;
//		TotalMarksQuiz[i] = a;
//	}
//	for (int i = 0;i < TotalAssignment;i++)
//	{
//		int a = 0;
//		file >> a;
//		TotalMarksAssignment[i] = a;
//	}
//}
//void EvalReport::DeleteStaticData()
//{
//	delete[] TotalMarksQuiz;
//	delete[] TotalMarksAssignment;
//	delete[] minimumQ;
//	delete[] maximumQ;
//	delete[] AverageQ;
//	delete[] minimumA;
//	delete[] maximumA;
//	delete[] AverageA;
//}
//EvalReport* ReadDataFromFile(ifstream& file)
//{
//	int temp[10];
//	char tem[80];
//	EvalReport::SetStaticData(file);
//	int tQuiz = EvalReport::GetTotalQuiz();
//	int tAssign = EvalReport::GetTotalAssignment();
//	int size = EvalReport::GetTotalStudents();
//	EvalReport* list = new EvalReport[size];
//	for (int i = 0;i< size;i++)
//	{
//		file >> tem;		//setting roll number
//		list[i].SetRollNumber(tem);
//		file.ignore();
//		file.getline(tem, 80);		//setting name
//		list[i].SetName(tem);
//		GetMarks(file, temp, tQuiz);		//setting quiz marks
//		list[i].SetQuiz(temp);
//		GetMarks(file, temp, tAssign);		//setting assignment marks
//		list[i].SetAssignment(temp);
//		list[i].SetTotal();
//	}
//	return list;
//}
//ostream& operator<<(ostream& cout,const EvalReport& a)
//{
//	cout << a.RollNumber<<"\t"<<a.Name<<"\t";
//	for (int i = 0;i < a.TotalQuiz;i++)
//	{
//		cout << a.quiz[i] << "\t";
//	}
//	for (int i = 0;i < a.TotalAssignment;i++)
//	{
//		cout << a.assignment[i] << "\t";
//	}
//	cout << a.total;
//	return cout;
//}
//void PrintAll(EvalReport* list)
//{
//	cout << "---------------------------------------------------------------------------------------------\n";
//	cout << "\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\n";
//	EvalReport::PrintStatistics();
//	cout << "\n---------------------------------------------------------------------------------------------\n";
//	cout << "Roll Number\tName\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\tTotal\n";
//	int size = EvalReport::GetTotalStudents();
//	for (int i = 0;i < size;i++)
//	{
//		cout << list[i];
//		cout << endl;
//	}
//}
//void PrintAll(EvalReport* list, int size)
//{
//	for (int i = 0;i < size;i++)
//	{
//		cout << "RollNumber: " << list[i].RollNumber << endl;
//		cout << "Name: " << list[i].Name << endl;
//		cout << "Quiz:\n";
//		cout << "Number\tObtained Marks\tTotal Marks\tAverage\tMinimum\tMaximum\n";
//		for (int j = 0;j < EvalReport::TotalQuiz;j++)
//		{
//			cout << j + 1 << "\t\t" << list[i].quiz[j] << "\t\t" << EvalReport::TotalMarksQuiz[j] << "\t" << EvalReport::AverageQ[j] << "\t" << EvalReport::minimumQ[j] << "\t" << EvalReport::maximumQ[j] << "\n";
//		}
//		cout << "Assignment:\n";
//		cout << "Number\tObtained Marks\tTotal Marks\tAverage\tMinimum\tMaximum\n";
//		for (int j = 0;j < EvalReport::TotalQuiz;j++)
//		{
//			cout << j + 1 << "\t\t" << list[i].assignment[j] << "\t\t" << EvalReport::TotalMarksAssignment[j] << "\t" << EvalReport::AverageA[j] << "\t" << EvalReport::minimumA[j] << "\t" << EvalReport::maximumA[j] << "\n";
//		}
//	}
//}
//void SortListByTotal(EvalReport* list)
//{
//	int size = EvalReport::GetTotalStudents();
//	for (int i = 0; i < size; i++) 
//	{
//		for (int j = i; j < size; j++)
//		{
//			if (list[i].total > list[j].total)
//			{
//				EvalReport temp = list[i];
//				list[i] = list[j];
//				list[j] = temp;
//			}
//		}
//	}
//}
//
//void main()
//{
//	ifstream file;
//	file.open("gradesheet.txt");
//	EvalReport* list = ReadDataFromFile(file);
//	file.close();
//	EvalReport::UpdateStatistics(list);
//	PrintAll(list);
//	char temp[10] = { "15L-1234" };
//	int count;
//	EvalReport* list1 = EvalReport::SearchStudentsByKeyWord(list, temp,count);
//	cout << endl;
//	if (list1)
//	{
//		PrintAll(list1, count);
//	}
//	else
//	{
//		cout << "Student Not Found\n";
//	}
//	char temp1[10] = {"15L-4023"};
//	EvalReport* list2 = EvalReport::SearchStudentsByKeyWord(list, temp1, count);
//	cout << endl;
//	if (list2)
//	{
//		PrintAll(list2, count);
//	}
//	else
//	{
//		cout << "Student Not Found\n";
//	}
//	SortListByTotal(list);
//	PrintAll(list);
//	EvalReport::DeleteStaticData();
//	delete[] list;
//	if (list1)
//	{
//		delete[] list1;
//	}
//	if (list2)
//	{
//		delete[] list2;
//	}
//}