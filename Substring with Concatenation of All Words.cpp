/*
	You are given a string, s, and a list of words, words, 
		that are all of the same length. Find all starting 
		indices of substring(s) in s that is a concatenation 
		of each word in words exactly once and without any 
		intervening characters.

	For example, given:
		s: "barfoothefoobarman"
		words: ["foo", "bar"]

	You should return the indices: [0,9].
	(order does not matter).
*/

//brutal force
class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        if(words.empty() || s.empty()) return {};
        unordered_map<string, int> m1, m2;
        for(auto &w : words)
            m2[w] = ++m1[w];
            
        vector<int> ret;
        
        int m = s.size(), n = words.size(), wlen = words[0].size();

        vector<bool> pass(s.size(), false);
        for(int i = 0; i <= m - n * wlen; ++i)
        {
            if(pass[i]) continue;
            int cnt = 0;
            for(int j = i; j < s.size(); j += wlen)
            {
                if(m2[s.substr(j, wlen)] == 0) break;
                m2[s.substr(j, wlen)]--;
                cnt++;
                if(cnt == n)
                {
                    ret.push_back(i);
                    break;
                }
            }
            m2 = m1;
        }
        return ret;
    }
};

//sliding window
class Solution 
{
public:
    vector<int> findSubstring(string S, vector<string> &L) 
    {
	    vector<int> res;
	    if (S.empty() || L.empty()) return res;
	    unordered_map<string, int> need;
	    for (int i = 0; i < L.size(); ++i)
	        need[L[i]]++;

	    int n = L[0].length(), m = L.size();

	    for (int i = 0; i < n; ++i) 
	    {
	        unordered_map<string, int> find;
	        for (int start = i, end = i, count = 0; end + n <= S.length(); end += n) 
	        {
	            string str = S.substr(end, n);
	            if (need.find(str) == need.end()) 
	            {
	                start = end + n;
	                find.clear();
	                count = 0;
	            }
	            else
	            {
	            	find[str]++;
	            	count++;
		            while (find[str] > need[str]) 
		            {
		                string subStart = S.substr(start, n);
		                find[subStart]--;
		                start += n;
		                --count;
		            }
		            if (count == m)
		            	res.push_back(start);
			    }
	        }
	    }
    	return res;
    }
};