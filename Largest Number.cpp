/*
    Given a list of non negative integers, arrange them such that they 
        form the largest number.

    For example, given [3, 30, 34, 5, 9], the largest formed number is 
        9534330.

    Note: The result may be very large, so you need to return a string 
        instead of an integer.
*/

class Solution 
{
public:
    string largestNumber(vector<int> &num) 
    {
        vector<string> arr;
        arr.reserve(num.size());
        for(auto i:num) arr.push_back(to_string(i));

        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1;});
        string res;
        for(auto &s:arr) res+=s;
        if (res[0] == '0') return "0"
        return res;
    }
};

class Solution {
private:
    struct myGreater
    {
        bool operator()(const string &s1, const string &s2)
        {
            cout << "s1 " << s1 << " s2 " << s2 << endl;
            int idx1 = 0, idx2 = 0;
            while (idx1 < s1.size() && idx2 < s2.size())
            {
                if (s1[idx1] != s2[idx2]) return s1[idx1] > s2[idx2];
                ++idx1; ++idx2;
            }
            if (idx1 == s1.size() && idx2 == s2.size()) return false;
            if (idx1 == s1.size()) return s1[0] > s2[idx2];
            else return s1[idx1] > s2[0];
        }
    };
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) 
    {
        // write your code here
        if (num.empty()) return "0";
        vector<string> vec(num.size());
        for (int i = 0; i < num.size(); ++i)
            vec[i] = to_string(num[i]);
        
        sort(vec.begin(), vec.end(), myGreater());
        string res;
        for (auto &s : vec) res += s;
        if (res[0] == '0') return "0";
        return res;
    }
};
