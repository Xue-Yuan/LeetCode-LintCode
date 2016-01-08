/*
    Compare two strings A and B, determine whether A contains all of the characters in B.

    The characters in string A and B are all Upper Case letters.
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        vector<int> vec(26, 0);
        for (auto &e : A)
            vec[e - 'A']++;
        for (auto &e : B)
            if (vec[e - 'A']-- == 0) return false;
        return true;
    }
};
