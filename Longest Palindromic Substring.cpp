#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int dp[1001][1001];

class Solution {
public:
	static string longestPalindrome(string s) {
		string s1 = s;
		int lenth = s.size();
		// s1 ��ֵΪs������
		for (int i = 0; i < lenth; i++)
		{
			s1[i] = s[lenth - 1 - i];
		}
		for (int i = 0; i <= lenth; i++)
		{
			dp[0][i] = 0;
			dp[i][0] = 0;
		}
		//�����s��i��β��s1��j��β��������Ӵ�����
		for (int i = 1; i <= lenth; i++)
		{
			for (int j = 1; j <= lenth; j++)
			{
				if (s[i-1] == s1[j-1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 0;
			}
		}
		//�жϻ����ַ�����ĳ���
		int maxlen = 0;
		int maxnum = 0;
		for (int i = 0; i <= lenth; i++)
		{
			for (int j = 0; j <= lenth; j++)
			{
				if (lenth-1-(i-dp[i][j])==j-1)
				{
					if (dp[i][j] > maxlen)
					{
						maxlen = dp[i][j];
						maxnum = i;
					}
				}
			}
		}

		return s.substr(maxnum - maxlen, maxlen);

	}
};
int main()
{
	string s = Solution::longestPalindrome("abbaba");
	cout << s << endl;;

	return 0;
}