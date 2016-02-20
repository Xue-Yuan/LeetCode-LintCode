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
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) return res;
        int M = S.size(), N = L.size();
        int K = L[0].size();
        unordered_map<string, int> need, found;
        for (int i = 0; i < N; ++i)
            need[L[i]]++;
        for (int i = 0; i <= M - N * K; ++i)
        {
            found.clear();
            int j;
            for (j = 0; j < N; ++j)
            {
                string s = S.substr(i + j * K, K);
                auto it = need.find(s);
                if (it == need.end()) break;
                if (it->second <= found[s]) break;
                found[s]++;
            }
            if (j == N) res.push_back(i);
        }
        return res;
    }
};

//sliding window
class Solution 
{
public:
vector<int> findSubstring(string s, vector<string>& words) 
    {
        if (s.empty() || words.empty()) return {};
        size_t s_sz = s.size(), w_sz = words[0].size();
        
        unordered_map<string, int> need;
        for (auto &w : words) 
            need[w]++;
        
        vector<int> ret;
        for (size_t i = 0; i < w_sz; ++i)
        {
            unordered_map<string, int> found;
            for (size_t start = i, end = i, count = 0; 
            	end + w_sz <= s_sz; end += w_sz)
            {
                string word = s.substr(end, w_sz);
                if (need.find(word) == need.end()) 
                {
                    start = end + w_sz;
                    found.clear();
                    count = 0;
                }
                else
                {
                    found[word]++; count++;
                    while (need[word] < found[word])
                    {
		                found[s.substr(start, w_sz)]--;
                        start += w_sz;
                        count--;
                    }
                    if (count == words.size()) ret.push_back(start);
                }
            }
        }
        return ret;
    }
};
