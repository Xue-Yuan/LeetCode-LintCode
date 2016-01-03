/*
    Given a digit string, return all possible letter combinations 
        that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons) 
        is given below.

    https://leetcode.com/problems/letter-combinations-of-a-phone-number/

    Input:Digit string "23"
        Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        vector<string> keyboard {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string s;
        letterCombinations(keyboard, digits, 0, s, res);
        return res;
    }
    
private:   
    void letterCombinations(vector<string> &keyboard, string &digits, int idx, string &s, vector<string> &res)
    {
        if (idx == digits.size())
        {
            res.push_back(s);
            return;
        }
        
        string &letters = keyboard[digits[idx] - '0'];
        for(size_t i = 0; i < letters.size(); ++i)
        {
            s.push_back(letters[i]);
            letterCombinations(keyboard, digits, idx + 1, s, res);
            s.pop_back();
        }
    }
};
