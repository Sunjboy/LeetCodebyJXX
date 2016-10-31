class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
		map<int,int> m;
		int t = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			int res = target - *it;
			map<int, int>::iterator i;
			if ((i = m.find(res)) != m.end())
			{
				v.push_back((*i).second);
				v.push_back(t);
				break;
			}
			m.insert(pair<int, int>(*it, t));
			t++;


		}
		return v;
	}
};
