/*
    Given a string array words, find the maximum value of 
        length(word[i]) * length(word[j]) where the two words do 
        not share common letters. You may assume that each word 
        will contain only lower case letters. If no such two words 
        exist, return 0.

    Example 1:
        Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
        Return 16
        The two words can be "abcw", "xtfn".

    Example 2:
        Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
        Return 4
        The two words can be "ab", "cd".

    Example 3:
        Given ["a", "aa", "aaa", "aaaa"]
        Return 0
        No such pair of words.
*/

class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        sort(words.begin(), words.end(), [](string &s1, string &s2){return s1.size() > s2.size();});
        
        vector<int> vec(words.size(), 0);
        
        for (int i = 0; i < words.size(); ++i)
            for (char &c : words[i])
                vec[i] |= (1 << (c - 'a'));
        
        size_t ret = 0;
        //Since vec.size() is of type size_t, we may come across
        //  problems if the size is of 0 and we use i < vec.size() - 1
        //  as the test condition.(It will run abnormally long time) I 
        //  think it is generally a good idea to do explicit type 
        //  conversion, say i < (int)vec.size() - 1.
        for (int i = 0; i < vec.size(); ++i)
        {
            for (int j = i + 1; j < vec.size(); ++j)
            {
                if ((vec[i] & vec[j]) != 0) continue;
                size_t tmp = words[i].size() * words[j].size();
                if (tmp < ret) continue;
                ret = tmp;
            }
        }
        return (int)ret;
    }
};