class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int l = 0, r = (int)s.size()-1;
        while (l < r) {
            bool l_found = vowels.find(s[l]) != string::npos;
            bool r_found = vowels.find(s[r]) != string::npos;
            if (l_found and r_found) {
                swap(s[l++], s[r--]);
            } else if (not l_found) {
                ++l;
            } else if (not r_found) {
                --r;
            }
        }
        return s;
    }
};
