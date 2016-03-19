/*
	找一个string中出现的第一个重复letter，字母区分大小写，if multiple characters recur, 
		pick the one whose first occurence is sooner, not the one whose second 
		occurrence is sooner.  复杂度小于等于O(nlogn)。 Assumption：至少有一个重复出现的字母。
*/

class Solution 
{
public:
	char func(const string &s)
	{
		int len = (int)s.size(), idx = len;
		vector<int> m(256, -1);
		for (int i = 0; i < len; i++)
			if (m[s[i]] != -1) idx = min(idx, m[s[i]]);
			else m[s[i]] = i;
		return s[idx];
	}
};
