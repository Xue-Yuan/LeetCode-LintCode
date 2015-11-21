#include <iostream>
// #include "algorithm.h"
// #include "algorithm.cpp"
#include <map>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <stack>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;

//check whether string s3 is the interleaving of string s1 and string s2
//dynamic programming
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> v(s1.size() + 1, vector<bool>(s2.size() + 1));
        v[0][0] = true;
        for(int j = 1; j <= s2.size(); ++j)
            v[0][j] = (v[0][j - 1] && (s2[j - 1] == s3[j - 1]));
        for(int i = 1; i <= s1.size(); ++i)
            v[i][0] = (v[i - 1][0]) && (s1[i - 1] == s3[i - 1]);

        for(int i = 1; i <= s1.size(); ++i)
        {
            for(int j = 1; j <= s2.size(); ++j)
            {   
                v[i][j] = (v[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (v[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
        return v[s1.size()][s2.size()];
    }
};

int main()
{
    Solution so;
    if(so.isInterleave("aabcc", "dbbca" , "aadbbcbcac"))
        cout << "True" << endl;
    return 0;
}
