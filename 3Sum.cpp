
bool cmp(int a, int b)
{
	return a<b;
}// increase




class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> v;
		map<pair<int, int>, int> m;
		std::sort(nums.begin(),nums.end(),cmp);
		/*for(vector<int>::iterator it = nums.begin(); it != nums.end(); it ++ )
		{
			printf("%d",*it);

		}*/

		int size = nums.size();
		for (int z = 0; z < size; z++)
		{
			int i = z+1;
			int j = size-1;
			int res = nums[z];
			while (i < j)
			{
				if (res + nums[i] + nums[j] < 0)
				{
					i++;
				}
				else if (res + nums[i] + nums[j] > 0)
				{
					j--;
				}
				else
				{
					if (m.find(pair<int, int>(res, nums[i])) != m.end())
					{
						i++; 
						j--;
						continue;
					}
					vector<int> temp;
					temp.push_back(res);
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					v.push_back(temp);
					m.insert(pair< pair<int, int>, int >(pair<int, int>(res, nums[i]), 1));
					i++; 
					j--;
				}
			}


		}
		return v;
	}
};