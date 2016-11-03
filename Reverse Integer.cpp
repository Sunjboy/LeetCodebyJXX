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
	static int reverse(int x)
	{
		long long m = x;
		bool flag = true;
		if (m < 0)
		{
			flag = false;
			m = 0 - m;
		}
		long long res = 0;
		int count = 0;
		while (m / 10 != 0)
		{
			res = res * 10;
			res = res + (unsigned int)m % 10;
			m = m / 10;
			count++;
		}
		res *= 10;
		res = res + m;
		if (res > 2147483647)
			return 0;
		if (!flag)
			res = (long long)0 - res;
		return res;

	}
};
int main()
{
	//vector<int> height = {1,1,1,0};
	//Solution
	int x = 0-2147483648;
	cout << Solution::reverse(x) << endl;


	return 0;
}