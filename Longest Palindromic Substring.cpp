/*
    Given a string S, find the longest palindromic substring 
        in S. You may assume that the maximum length of S is 
        1000, and there exists one unique longest palindromic 
        substring.
    http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/
//Manacher's
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^#";
        for (char &ch : s) {
            t += ch;
            t += '#';
        }
        t += '$';
        vector<int> length(t.size(), 0);
        int radius = 0, center = 0;
        for (int i = 1; i < (int)t.size()-1; i++) {
            int mirror_i = center * 2 - i;
            length[i] = (radius > i) ? min(radius - i, length[mirror_i]) : 0;
            while (t[i+1+length[i]] == t[i-1-length[i]]) {
                length[i]++;
            }
            if (i + length[i] > radius) {
                radius = i + length[i];
                center = i;
            }
        }
        int max_center = max_element(length.begin(), length.end()) - length.begin();
        int max_length = length[max_center];
        return s.substr((max_center-max_length-1)/2, max_length);
    }
};


//We don't have to actually preprocess the string
class Solution2 {
    string longestPalindrome_2(string s) 
    {
        vector<int> P(2 * s.size() + 3, 0);

        int C = 0, R = 0;
        for(int i = 1; i < P.size() - 1; ++i)
        {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            //^#a#a#$   --padding in odd index, char in even
            int left = i - 1 - P[i], right = i + 1 + P[i];
            for(;left > 0 && right <= P.size() + 1; --left, ++right)
            {
                if((left & 0x1) || s[(left - 1) / 2] == s[(right - 1) / 2])
                    P[i]++;
                else
                    break;
            }

            if(i + P[i] > R)
            {
                R = i + P[i];
                C = i;
            }

        }
        int maxLen = 0, cen = 0;
        for(int i = 1; i < P.size() - 1; ++i)
        {
            if(P[i] > maxLen)
            {
                maxLen = P[i];
                cen = i;
            }
        }
        // cout << cen << ' ' << maxLen << endl;
        return s.substr((cen - maxLen) / 2, maxLen);
    }
};
