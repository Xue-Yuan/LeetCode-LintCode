/*
    Given a string that contains only digits 0-9 and a target value, return 
        all possibilities to add binary operators (not unary) +, -, or * between 
        the digits so they evaluate to the target value.

    Examples: 
        "123", 6 -> ["1+2+3", "1*2*3"] 
        "232", 8 -> ["2*3+2", "2+3*2"]
        "105", 5 -> ["1*0+5","10-5"]
        "00", 0 -> ["0+0", "0-0", "0*0"]
        "3456237490", 9191 -> []
*/
class Solution {
public:
    vector<string> addOperators(string num, int target) 
    {
        if (num.empty()) return {};
        
        tar = target;
        dfs(num, 0, "", 0, 0, ' ');
        return ret;
    }
private:
    void dfs(string &num, size_t idx, string path, long val, 
        long prev, char op)
    {
        if (idx == num.size() && val == tar)
        {
            ret.push_back(path);
            return;
        }
        
        for (size_t len=1; idx+len<=num.size(); len++)
        {
            string cur = num.substr(idx, len);
            if (len != 1 && cur[0] == '0') break;
            long v = stol(cur);
            if (idx == 0) dfs(num, idx+len, cur, v, v, '+');
            else 
            {
                dfs(num, idx+len, path+"+"+cur, val+v, v, '+');
                dfs(num, idx+len, path+"-"+cur, val-v, v, '-');
                if (op == '+')
                    dfs(num, idx+len, path+"*"+cur, val-prev+prev*v, prev*v, '+');
                else if (op == '-')
                    dfs(num, idx+len, path+"*"+cur, val+prev-prev*v, prev*v, '-');
            }
        }
    }
private:
    vector<string> ret;
    int tar;
};
