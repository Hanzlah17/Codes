#include<iostream>
using namespace std;
const int s = 13;
template <class T>
class Stack
{
private:
	int top;
	T stack[];
public:
	Stack()
	{
		top = -1;
		stack[s];
	}
	bool isFull()
	{
		return (top == s - 1);
	}
	void push(T data)
	{
		if (isFull())
		{
			cout << "Stack is full\n";
			return;
		}
		top++;
		stack[top] = data;
	}
	bool Top(T& data)
	{
		if (isEmpty())
		{
			return false;
		}
		data = stack[top];
	}
	bool isEmpty()
	{
		return (top == -1);
	}
	void pop()
	{
		if (top == -1)
		{
			cout << "Stack is Empty\n";
			return;
		}
		top--;
	}
	~Stack() {}
};
bool isBalanced(string str)
{
	Stack<char> obj;
	int length = str.length();
	if (length == 0)
	{
		return false;
	}
	for (int i = 0;i < length;i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			obj.push(str[i]);
		}
		else
		{
			if (obj.isEmpty())
			{
				return false;
			}
			char top;
			obj.Top(top);
			obj.pop();
			if ((top == '(' && str[i] != ')') || (top == '{' && str[i] != '}') || (top == '[' && str[i] != ']'))
			{
				return false;
			}
		}
	}
	return obj.isEmpty();
}
int SumOfDig(int num)
{
	if (num == 0)
	{
		return num;
	}
	int r = num % 10;
	return r + SumOfDig(num / 10);
}
void main()
{
	cout << "Sum of Digits= " << SumOfDig(77) << endl;
	string str = "{[{}{}]}[())]";
	cout << "Expression is ";
	if (isBalanced(str))
	{
		cout << "balanced\n";
	}
	else
	{
		cout << "not balanced\n";
	}
}
