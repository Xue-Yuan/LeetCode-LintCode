class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (char ch : (s+t)) {
            ans ^= ch;
        }
        return ans;
    }
};
