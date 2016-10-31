#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int dp[1001];

class Solution {
public:
	static string longestPalindrome(string s) {
		string s1(2*s.size()+1,'#');
		int lenth = s.size();
		for (int i = 0; i < lenth; i++)
		{
			s1[2 * i + 1] = s[i];
		}
		lenth = 2 * lenth + 1  ;
		int maxid = -1;
		int id = -1;

		int resid = -1;
		int maxdp = -1;
		for (int i = 0; i < lenth; i++)
		{
			dp[i] = 1;
			if (maxid < 0)
			{
				id = 0;
				maxid = 0;
				continue;
			}
			if (maxid - i >= 0)
			{
				int temp = 2 * id - i;
				if (i + dp[temp] - 1 < maxid)
					dp[i] = dp[temp];
				else
				{
					dp[i] = maxid - i + 1;
				}
			}
			//extend bounds
 			int j = 1;
			while (1)
			{
				if (dp[i] - 1 + i + j < lenth && i - dp[i] + 1 - j >= 0)
				{
					if (s1[dp[i] - 1 + i + j] == s1[i - dp[i] + 1 - j])
						j++;
					else
						break;
				}
				else
					break;
			}
			j--;
			dp[i] += j;
			if (i + dp[i] - 1 > maxid)
			{
				maxid = i + dp[i] - 1;
				id = i;
			}
			if (dp[i] > maxdp)
			{
				maxdp = dp[i];
				resid = i;
			}
				

		}

		string res;
		if (s1[resid] == '#')
		{
			res = s.substr((resid - maxdp+1) / 2, maxdp - 1);
		}
		else
		{
			res = s.substr((resid - 1) / 2 - maxdp / 2 + 1, maxdp - 1);
		}
		return res;
	}
};
int main()
{
	string s = Solution::longestPalindrome("abb");
	cout << s << endl;;

	return 0;
}