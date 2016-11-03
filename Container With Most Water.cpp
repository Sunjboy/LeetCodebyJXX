#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
	static int maxArea(vector<int>& height) 
	{
		int res = 0;
		int num = height.size();
		vector<pair<int,int>> left;
		vector<pair<int,int>> right;
		for (int i = 0; i < num; i++)
		{
			if (i == 0)
			{
				left.push_back(make_pair(i,height[i]));
			}
			else if (height[i] > left.back().second)
			{
				left.push_back(make_pair(i, height[i]));
			}
		}
		for (int i = num - 1; i >= 0; i--)
		{
			if (i == num - 1)
			{
				right.push_back(make_pair(i, height[i]));
			}
			else if (height[i] > right.back().second)
			{
				right.push_back(make_pair(i, height[i]));
			}
		}

		for (int i = 0; i < left.size(); i++)
		{
			for (int j = 0; j < right.size(); j++)
			{
				if (left[i].first < right[j].first)
				{
					int temp = (right[j].first - left[i].first)*(left[i].second < right[j].second ? left[i].second : right[j].second);
					if (temp > res)
						res = temp;
				}
			}
		}

		return res;
	}
};
int main()
{
	vector<int> height = {5,4,3,9,6,6,7};
	cout<<Solution::maxArea(height)<<endl;

	return 0;
}