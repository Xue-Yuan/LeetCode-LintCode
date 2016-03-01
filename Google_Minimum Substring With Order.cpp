/*
    求string str1中含有string str2 order的 subsequence 的最小长度

    举个例子： str1 = "acbacbc"   str2="abc", 那么最小subsequence长度应该是4， 
        对应的subsequence是“acbc”
*/
class Solution
{
public:
    int minSubsequence(const string &s1, const string &s2)
    {
        if (s2.empty()) return 0;

        int len1 = (int)s1.size(), len2 = (int)s2.size();
        int ret = len1+1;
        for (int i = 0; i < len1; i++)
            if (s1[i] == s2[0])
            {
                int end = 0;
                for (int j = i; j < len1; j++)
                {
                    end += s1[j] == s2[end];
                    if (end == len2)
                    {
                        ret = min(ret, j-i+1);
                        break;
                    }
                }
            }

        return ret == (len1+1) ? -1 : ret;
    }
};
