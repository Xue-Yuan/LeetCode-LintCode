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

/*
    The idea is to compare the strings by bit manipulation, since
        it's much faster than comparing one character after one 
        character.
*/
class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        vector<unsigned> vec(words.size());
        
        int len = words.size();
        for (int i = 0; i < len; ++i)
        {
            unsigned tmp = 0;
            for (char &ch : words[i])
                tmp |= 1<<(ch-'a');
            vec[i] = tmp;
        }
        
        size_t ret = 0;
        for (int i = 0; i < len; ++i)
            for (int j = i+1; j < len; ++j)
                if (!(vec[i] & vec[j]))
                    ret = max(ret, words[i].size()*words[j].size());
        
        return (int)ret;
    }
};
