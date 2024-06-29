//#include<iostream>
//#include<string.h>
//using namespace std;
//string DecodeString(string str, int& index)
//{
//	string result = "";
//	int count = 0;
//	if (index >= str.length())
//	{
//		return result;
//	}
//	while (index < str.length())
//	{
//		if (str[index] >= '0' && str[index] <= '9')
//		{
//			char curr = str[index];
//			count = atoi(&curr);
//			index++;
//			string temp = DecodeString(str, index);
//			index++;
//			for (int i = 0;i < count;i++)
//			{
//				result = result + temp;
//			}
//
//		}
//		else
//		{
//			if (str[index] == '[')
//			{
//				index++;
//			}
//			else if (str[index] == ']')
//			{
//				return result;
//			}
//			else
//			{
//				result = result + str[index];
//				index++;
//			}
//		}
//	}
//	return result;
//}
//void main()
//{
//	string str = "3[a]2[bc]";
//	int index = 0;
//	cout << "decoded string: " << DecodeString(str, index);
//}