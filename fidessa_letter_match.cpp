class Solution
{
public:
	int func(const string &str)
	{
		if (str.empty() || !isupper(str[0]))
			return -1;

		std::stack<char> stk;
		int idx = -1, len = (int)str.size();
		for (int i = 0; i < len; i++)
		{
			if (isupper(str[i])) stk.push(str[i]);
			else
			{
				if (!stk.empty())
				{
					if (isMatch(stk.top(), str[i]))
					{
						idx = i;
						stk.pop();
					}
					else return idx;
				}
				else return idx;
			}
		}
		return idx;
		
	}
private:
	bool isMatch(const char &a, const char &b)
	{
		return a != b && a == toupper(b);
	}
};
