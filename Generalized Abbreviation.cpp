/*
    Write a function to generate the generalized abbreviations of a word.

    Example:
        Given word = "word", return the following list (order does not matter):
        ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
            "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

//Simple idea, change each position anyway, and check if previous charater is a digit.
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ret;
        int len = word.size();
        for (int i = 0; i <= len; ++i)
            generate(word, ret, i, 0);
        return ret;
    }
private:
    void generate(string &word, vector<string> &ret, int len, int start)
    {
        if (len == 0)
        {
            ret.push_back(word);
            return;
        }
        if (start >= (int)word.size()) return;
        
        for (int i = start; i < (int)word.size(); ++i)
        {
            char save = word[i];
            word[i] = '1';
            if (i > 0 && isdigit(word[i-1]))
            {
                int beg = i;
                while (beg > 0 && isdigit(word[beg-1])) beg--;
                string tmp = word.substr(0, beg) + to_string(stoi(word.substr(beg, i-beg)) + 1);
                int new_start = tmp.size();
                tmp += word.substr(i+1);
                generate(tmp, ret, len-1, new_start);
            }
            else generate(word, ret, len-1, i+1);
            word[i] = save;
        }
    }
};

class Solution2 {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ret;
        generate(word, "", 0, 0, ret);
        return ret;
    }
private:
    void generate(string &word, string cur, int idx, int cnt, vector<string> &ret)
    {
        
        if (idx == (int)word.size())
        {
            if (cnt > 0) cur += to_string(cnt);
            ret.push_back(cur);
            return;
        }
        
        //do not abbreviate the character word[idx]
        generate(word, cur+(cnt ? to_string(cnt) : "")+word[idx], idx+1, 0, ret);
        //abbreviate it
        generate(word, cur, idx+1, cnt+1, ret);
    }
};
