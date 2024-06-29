#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
bool wordBreak(string s, vector<string>& wordDict)
{
	//using a dynamic approach
	int length = s.size();
	int max_length = 0;
	//finding the maxlength a word could be in dictionary
	for (auto str : wordDict)
	{
		max_length = max(max_length, (int)str.size());
	}
	//initializing a DP array which would store if substring of length i is part of dictionary
	vector<bool> dp(length + 1, false);
	dp[0] = true; //word of length zero can always be segmented hence true
	//creating a map so that we can search a substring in dictionary more efficiently
	unordered_set<string> words(wordDict.begin(), wordDict.end());
	for (int i = 1;i < length + 1;i++)
	{
		int limit = max(i - max_length, 0); //checking the substrings that are less than or equal to biggest word in dictionary
		for (int j = i - 1;j >= limit;j--)
		{
			string substr = s.substr(j, i - j); //we fetch a substring startin from index j of length i-j
			if (dp[j] && words.find(substr) != words.end()) //if previous can be segmented and this substr also exist in our dictionary
			{
				dp[i] = true;  //substr of length i can be segmenetd too
				break; //no need to check furthur
			}
		}
	}
	return dp[length];
}