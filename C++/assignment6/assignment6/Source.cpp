//#include<iostream>
//#include<fstream>
//using namespace std;
//
//
//class FlexEvaluation
//{
//	friend void UpdateStatistics(FlexEvaluation*);
//	friend FlexEvaluation* ReadDataFromFile(ifstream&); //While writing signature of function we do not write variable name. ONLY DATA TYPE. The reason is so we can write any name for variable while writing function
//	friend void PrintAll(FlexEvaluation*,int);
//
//private:
//
//	char* roll_no;
//	char* name;
//	static int totalNoQuiz, totalNoAssignments, totalStudents;
//	static int* quizstats;
//	static int* assignmentstats;
//	static int* totalQuiz;
//	static int* totalAssignment;
//	int* quiz;
//	int* assignment;
//	int totalmarks;		//this integer will store total obtained marks of each student
//
//	//The Function written in private of class are called utility functions since they help the functions in public for their working. 
//	int stringLength(char* a)
//	{
//		int count = 0;
//		for (int i = 0; a[i] != '\0'; i++)
//		{
//			count++;
//		}
//		return count;
//	}
//
//	void stringcpy(char* array, char* arr)
//	{
//		int i = 0;
//		for (i; array[i] != '\0'; i++)
//		{
//			arr[i] = array[i];
//		}
//		arr[i] = '\0';
//	}
//	void arraycpy(int* array, int* arr, int size)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = array[i];
//		}
//		
//	}
//public:
//
//	FlexEvaluation()
//	{
//		quiz = 0;
//		assignment = 0;
//		roll_no = 0;
//		name = 0;
//	}
//
//	~FlexEvaluation()
//	{
//		if (quiz && assignment && roll_no && name)//checking if the pointers are nor NULL i.e quiz!=0
//		{
//			delete[] quiz;
//			delete[] assignment;
//			delete[] roll_no;
//			delete[] name;
//		}
//	}
//
//	FlexEvaluation& operator=(const FlexEvaluation& a)
//	{
//		if (this != &a)
//		{
//			if (quiz && assignment && roll_no && name)//this is making sure that if these pointers have memory from heap then no leakage occur
//			{
//				delete[] quiz;
//				delete[] assignment;
//				delete[] roll_no;
//				delete[] name;
//			}
//			//now before copying data in these arrays we must give them memory since they are either null or dangling
//			//for this purpose we must know how much memory should be provided hence we will use Stringlength function
//			roll_no = new char[stringLength(a.roll_no) + 1];
//			stringcpy(a.roll_no, roll_no);//REMEMBER: your function copies 1st array in 2nd i.e 1st is source and 2nd is destination.
//			//--------DO SAME FOR "name"-----------//
//
//			//now we also have two integer arrays. We wont need stringLength for it.WHY??
//			//moreover we cannot use Stringcpy for it....WHY??
//			quiz = new int[totalNoQuiz];	//totalNoQuiz is member of class and can be accesed in PUBLIC
//			arraycpy(a.quiz, quiz, totalNoQuiz);//REMEMBER: your function copies 1st array in 2nd i.e 1st is source and 2nd is destination.
//			//--------DO SAME FOR "assignmnet"-----------//
//			//Although we have same number of quiz and assignment but to give memory use totalNoAssignment.
//
//			totalmarks = a.totalmarks;
//		}
//		return *this;
//	}
//	void SetRollNumber(char* temp)
//	{
//		//first provide memory to private member
//		roll_no = new char[stringLength(temp) + 1];
//		stringcpy(temp, roll_no);	//setting the data
//	}
//	void SetName(char* temp)
//	{
//		//-----Write yourslef---------//
//	}
//	void SetQuiz(ifstream& file)
//	{
//		//first provide memory to private member
//		int size = totalNoQuiz;		//note that while in the class you can access static member without "FlexEvaluation::"
//		quiz = new int[size];
//		for (int i = 0;i < size;i++)
//		{
//			int s = 0;
//			file >> s;
//			quiz[i] = s;
//		}
//	}
//	void SetAssignment(ifstream& file)
//	{
//		//-----Write yourslef---------//
//	}
//	void SetTotalMarks()
//	{
//		//--------write yourself--------//
//		//this function will add all the marks in quiz and assignment and store in totalmarks
//		totalmarks =0 ;//sum of both arrays
//	}
//	FlexEvaluation(const FlexEvaluation& a)
//	{
//		//-----NO CHECK REQUIRED---//.....WHY???
//		//second check is also not requird...WHY???
//		
//
//		//TAKE THE CODE FROM ASSIGNMENT OPERATOR AND PASTE IT//
//		//no return value
//	}
//	void Print()
//	{
//		//Print all the non-static private members in it i.e roll number name marks and totalobtained.
//	}
//	static void PrintStats()		//this is a static function we do not need "dot" to call it.
//	{
//		//PRINT max min avg and total in this function	i.e print arrays quizstats,assignmentstats,totalquiz and totalassignment
//		//the size of quizstats and assignment stats is 3 times the totalNoQuiz and totalNoAssignment respectively
//	}
//	static void DeleteStatic()
//	{
//		//since we cannot delete static in destructor we will do this in this function.
//		//---------DELETE ALL STATIC DATA IN THIS FUNCTION-----------------//
//		//---------DO NOT FORGET THE CHECK FOR NULL POINTER---------------//
//	}
//	static int GetTotalStudents()
//	{
//		return totalStudents;
//	}
//};
//
////-----------INITIALIZING ALL THE STATIC MEMBERS---------------//
////-----------REMEMBER ONLY STATIC MEMBERS----------------------//
//int FlexEvaluation::totalStudents = 0;
////-------DO SAME FOR REST INTEGERS------------------//
//int* FlexEvaluation::quizstats = 0;
////-------DO SAME FOR REST INTEGER POINTERS------------------//
//
//
//FlexEvaluation* ReadDataFromFile(ifstream& file)		//the friend functions are written outside class
//{
//	int temp = 0;	//we use a temporary integer to read data from file because it doesnt read correctly if used directly
//	file >> temp;
//	//------We do not need setters or getters for static members----------//
//	FlexEvaluation::totalStudents = temp;	//this is the way of changing the value of static member. NOTICE it does not have "int" used in initializing.
//	file >> temp;
//	FlexEvaluation::totalNoQuiz = temp;
//	//--------DO THE SAME FOR ASSIGNMENT--------//
//
//	//NOW SETTING THE VALUE OF TOTAL NUMBERS//
//	int size = FlexEvaluation::totalNoQuiz;			//we can get the value of a static member without getter
//	FlexEvaluation::totalQuiz = new int[size];	//providing the required memory
//	for (int i = 0;i < size;i++)
//	{
//		file >> temp;
//		FlexEvaluation::totalQuiz[i] = temp;
//	}
//	//--------DO THE SAME FOR ASSIGNMENT--------//
//
//	//--------now we have to save data of each student----------//
//	//--------for this purpose we have to create an array of objects. WE DO NOT NEED A 2D ARRAY------//
//	int total = FlexEvaluation::totalStudents;
//	FlexEvaluation* studentlist = new FlexEvaluation[total];	//taking memory for students in 1D ARRAY
//	//now taking data from file and giving to each object in array one by one
//	char temp1[80];		//making two buffers to take data from file
//	int buffer[10];
//	for (int i = 0;i < total;i++)
//	{
//		file >> temp1;
//		studentlist[i].SetRollNumber(temp1);	//since now we are dealing with non static members we will need setters
//		file.getline(temp1, 80);
//		studentlist[i].SetName(temp1);
//		//now to take data integer in integer array we need loop. Either you can make a funtion that takes file and read array in buffer or provide file directly to setter
//		//in this case i am providing the file directly to setter
//		studentlist[i].SetQuiz(file);
//		studentlist[i].SetAssignment(file);
//		studentlist[i].SetTotalMarks();
//	}
//	return studentlist;		//returning the list so can be accessed in main
//}
//void UpdateStatistics(FlexEvaluation* data)		//we are required with data of students to calculate students
//{
//	//Take memory requird for data
//	int size = FlexEvaluation::totalNoQuiz;
//	//since we have 3 stats for each quiz hence we require size which is 3 times of number of quiz
//	FlexEvaluation::quizstats = new int[size*3];
//	//the array would be arranged as minimum of all quizes then maximum and then avg
//	int total = FlexEvaluation::totalStudents;
//	int k = 0;
//	for (int i = 0;i < size;i++)	//this loop is checking quiz number
//	{
//		int min = 10000;
//		for (int j = 0;j < total;j++)	//this loop is checking marks of each student in that quiz i.e if i=0 then quiz1 and i=3 then quiz4
//		{
//			if (data[j].quiz[i] < min)
//			{
//				min = data[j].quiz[i];
//			}
//		}
//		FlexEvaluation::quizstats[k] = min;
//		k++;	//separate index for quizstat array
//	}
//	//--------Write the same code for maximum and average----------//
//	//--------!!Do not change the value of "k"!!-----------//
//}
//void PrintAll(FlexEvaluation* data,int size)
//{
//	cout << "------------------------------------------------------------------------------------------------------------\n";
//	FlexEvaluation::PrintStats();	//this is how to call a static function. NOTICE no "dot" required to call it.
//	cout << "\n------------------------------------------------------------------------------------------------------------\n";
//	for (int i = 0;i < size;i++)
//	{
//		data[i].Print();
//	}
//}
//void main()
//{
//	ifstream file;
//	file.open("filename.txt");
//	FlexEvaluation* studentlist = ReadDataFromFile(file);
//	file.close();
//	UpdateStatistics(studentlist);
//	int size = FlexEvaluation::GetTotalStudents();
//	PrintAll(studentlist, size);
//
//
//	FlexEvaluation::DeleteStatic();
//	delete[] studentlist;
//}