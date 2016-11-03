#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
	static string intToRoman(int num) 
	{
		string res = "";
		char s[] = {'M','D','C','L','X','V','I'};//1000,500,100,50,10,5,1

		int base = 1000;
		int index = 0;
		while (base != 0 && num != 0)
		{
			if (num/base == 9)
			{
				res += s[index];
				res += s[index - 2];
			}
			else if (num/base == 4)
			{
				res += s[index];
				res += s[index - 1];
			}
			else
			{
				if (num / base >= 5)
				{
					res += s[index - 1];
					for (int i = 0; i < num / base - 5; i++)
					{
						res += s[index];
					}
				}
				else
				{
					for (int i = 0; i < num / base; i++)
					{
						res += s[index];
					}
				}
			}
			num = num%base;
			base = base / 10;
			index += 2;
		}
		return res;
	}
};
int main()
{
	//vector<int> height = {5,4,3,9,6,6,7};
	cout<<Solution::intToRoman(3999)<<endl;

	return 0;
}