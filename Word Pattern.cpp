/*
    Given a pattern and a string str, find if str follows the same pattern.

    Here follow means a full match, such that there is a bijection between 
        a letter in pattern and a non-empty word in str.

    Examples:
        pattern = "abba", str = "dog cat cat dog" should return true.
        pattern = "abba", str = "dog cat cat fish" should return false.
        pattern = "aaaa", str = "dog cat cat dog" should return false.
        pattern = "abba", str = "dog dog dog dog" should return false.

    You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution 
{
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        istringstream p(pattern), in(str);
        string s; char c;
        while (p >> c && in >> s)
        {
            if (m1.find(c) != m1.end() && m1[c] != s) return false;
            if (m2.find(s) != m2.end() && m2[s] != c) return false;
            m1[c] = s;
            m2[s] = c;
        }
        return p.eof() && in.eof();
    }
};