#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	static vector<string> letterCombinations(string digits) 
	{
		vector<string> v;
		queue<string> q;
		vector<string> map = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		int lenth = digits.size();
		q.push("");
		for (int i = 0; i < lenth; i++)
		{
			if (digits[i] > '9' || digits[i] < '2')
				continue;

				while (!q.empty())
				{
					string s = q.front();
					if (s.size() == i+1)
						break;
					else 
					{
						q.pop();
						for (int j = 0; j < map[(digits[i] - '2')].size(); j++)
						{
							q.push(s + map[(digits[i] - '2')][j]);
						}
					}
				}
		}
		int size = q.size();
		if (size == 1)//输入为空时，因为之前插入了空串，所以会导致返回空串
			return v;
		while(!q.empty())
		{
			v.push_back(q.front());
			q.pop();
		}
		return v;
	}
};
int main()
{
	//vector<int> height = {1,1,1,0};
	vector<string> v = Solution::letterCombinations("23");
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}