/*
    A strobogrammatic number is a number that looks the same when rotated 180 
        degrees (looked at upside down).

    Write a function to determine if a number is strobogrammatic. The number 
        is represented as a string.

    For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/
class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<int> m(10, -1);
        m[1] = 1; m[0] = 0; m[9] = 6;
        m[8] = 8; m[6] = 9;
        
        int start = 0, end = (int)num.size()-1;
        while (start <= end)
        {
            if (m[num[start]-'0'] < 0) return false;
            if (m[num[start++]-'0'] != num[end--]-'0')
                return false;
        }
        
        return true;
    }
};
