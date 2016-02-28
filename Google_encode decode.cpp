class Solution
{
public:
    string encode(string s)
    {
        if (s.empty()) return "";
        string ret;
        int len = (int)s.size(), start = 0, end = 0;
        while (end < len)
        {
            if (s[start] == s[end])
                end++;
            else
            {
                ret += to_string(end-start) + "x" + s[start];
                start = end;
            }
        }
        ret += to_string(end-start) + "x" + s[start];
        return ret;
    }

    string decode(string s)
    {
        if (s.empty()) return "";
        int len = (int)s.size(), start = 0, end = 0;
        string ret;
        while (end < len)
        {
            if (isdigit(s[end])) 
                end++;
            else
            {
                int num = stoi(s.substr(start, end-start));
                ret += string(num, s[end+1]);
                start = (end += 2);
            }
        }
        return ret;
    }
};
