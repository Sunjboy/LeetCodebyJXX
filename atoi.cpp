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
			//������ֿո�ȷ��ţ��������ַ����ײ����֣�������
			if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && !mark)
				continue;
			//������Ѿ����ֹ����֣��ٳ����˿ո���ֹͣ��󿴣�����ѭ��
			else if((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && mark)
				break;

			//������������ţ������ǲ��ǵ�һ�γ����������ţ�������ǣ�������ѭ��������ǵ�һ�γ�������
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
			//�������int���ƣ��򷵻��ܱ�ʾ����������Сֵ
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