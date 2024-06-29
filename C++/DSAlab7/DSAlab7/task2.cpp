#include<iostream>
#include<vector>
using namespace std;
void Combinations(vector<int>& arr, int com, vector<int>& result, int index)
{
	if (com == 0)
	{
		for (int i = 0;i < result.size();i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}
	if (index >= arr.size())
	{
		return;
	}
	result.push_back(arr[index]);
	Combinations(arr, com - 1, result, index + 1);
	result.pop_back();
	Combinations(arr, com, result, index + 1);
}
void main()
{
	vector<int> array = { 1,2,3,4 };
	vector<int> result;
	Combinations(array, 3, result, 0);
}