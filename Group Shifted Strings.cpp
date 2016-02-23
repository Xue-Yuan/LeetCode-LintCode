/*
    Given a string, we can "shift" each of its letter to its successive letter, 
        for example: "abc" -> "bcd". We can keep "shifting" which forms the 
        sequence:

            "abc" -> "bcd" -> ... -> "xyz"
    Given a list of strings which contains only lowercase alphabets, group 
        all strings that belong to the same shifting sequence.

    For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
        Return:

            [
              ["abc","bcd","xyz"],
              ["az","ba"],
              ["acef"],
              ["a","z"]
            ]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (auto &str : strings)
            m[stringToPattern(str)].push_back(str);
        
        vector<vector<string>> ret;
        for (auto itr = m.begin(); itr != m.end(); ++itr)
        {
            ret.push_back((*itr).second);
            sort(ret.back().begin(), ret.back().end());
        }
        return ret;
    }
private:
    string stringToPattern(string &s)
    {
        string ret;
        for (size_t i = 1; i < s.size(); ++i)
        {
            int diff = s[i]-s[i-1];
            ret += (diff > 0) ? (diff + 'a') : (diff + 'a' + 26);
        }
        return ret;
    }
};
