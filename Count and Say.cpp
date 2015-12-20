/*
    The count-and-say sequence is the sequence of integers 
        beginning as follows:
    
        1, 11, 21, 1211, 111221, ...

    1 is read off as "one 1" or 11.

    11 is read off as "two 1s" or 21.

    21 is read off as "one 2, then one 1" or 1211.

    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.
*/

class Solution 
{
public:
    string countAndSay(int n) 
    {
        string s1 = "1", s2 = "";
        for (int i = 1; i < n; ++i)
        {
            int idx = 0;
            while (idx < s1.size())
            {
                int cnt = 1;
                while (idx + 1 != s1.size() && s1[idx + 1] == s1[idx])
                    idx++, cnt++;
                s2 += to_string(cnt) + s1[idx++];
            }
            s1 = move(s2);
            s2 = "";
        }
        return s1;
    }
};

class Solution2 
{
public:
    string countAndSay(int n) 
    {
        string res = "1";
        for (int i = 2; i <= n; ++i)
        {
            stringstream ss;
            int j = 0, N = res.size();
            while (j < N) 
            {
                int k = j + 1;
                while (k < N && res[k] == res[j])
                    k++;
                ss << (k - j) << res[j];
                j = k;
            }
            ss >> res;
        }
        return res;
    }
};