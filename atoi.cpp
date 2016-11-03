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
	static int myAtoi(string str) 
	{
		long long res = 0;
		int lenth = str.size();
		bool flag = true;
		bool mark = false;
		for (int i = 0; i < lenth; i++)
		{
			//如果出现空格等符号，并且是字符串首部出现，则跳过
			if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && !mark)
				continue;
			//如果是已经出现过数字，再出现了空格，则停止向后看，跳出循环
			else if((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && mark)
				break;

			//如果是正负符号，区分是不是第一次出现正负符号，如果不是，则跳出循环，如果是第一次出现则标记
			if (str[i] == '+' || str[i] == '-')
			{
				if (mark)
					break;
				mark = true;
				if (str[i] == '-')
					flag = false;
				continue;
			}
			else if (str[i] < '0' || str[i] > '9')
			{
				break;
			}
			res = res * 10;
			res += str[i] - '0';
			mark = true;
			//如果超出int限制，则返回能表示的最大或者最小值
			if (flag && res > 2147483647)
			{
				return 2147483647;
			}
			else if (!flag && res > 2147483648)
			{
				return 0 - 2147483648;
			}
		}
		if (flag && res > 2147483647)
		{
			res = 2147483647;
		}
		else if (!flag && res > 2147483648)
		{
			res = 2147483648;
		}
		if (!flag)
			res = 0 - res;
		return int(res);

	}
};
int main()
{
	//vector<int> height = {1,1,1,0};
	//Solution
	int x = 0-2147483648;
	cout << Solution::myAtoi("+0 123") << endl;


	return 0;
}