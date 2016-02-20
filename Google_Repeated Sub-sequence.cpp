/*
	Given a string (1-d array) , find if there is any sub-sequence that 
		repeats itself. 
	Here, sub-sequence can be a non-contiguous pattern, with the same 
		relative order. 

	Eg: 

		1. abab <------yes, ab is repeated 
		2. abba <---- No, a and b follow different order 
		3. acbdaghfb <-------- yes there is a followed by b at two places 
		4. abcdacb <----- yes a followed by b twice 

	The above should be applicable to ANY TWO (or every two) characters 
		in the string and optimum over time. 

	In the sense, it should be checked for every pair of characters in the 
		string.
*/

//Adopt the longest common subsequence problem
class Solution
{
public:
	bool repeated_subsequence(string &s)
	{
		if (s.empty()) return false;
		vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));

		for (size_t i = 1; i <= s.size(); ++i)
			for (size_t j = 1; j <= s.size(); ++j)
				if (i != j && s[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

		return dp[s.size()][s.size()] >= 2;
	}
};
