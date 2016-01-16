/*
    Given two words (beginWord and endWord), and a dictionary's word 
        list, find the length of shortest transformation sequence from 
        beginWord to endWord, such that:

        1. Only one letter can be changed at a time
        2. Each intermediate word must exist in the word list

    For example,

        Given:
        beginWord = "hit"
        endWord = "cog"
        wordList = ["hot","dot","dog","lot","log"]

    As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
        return its length 5.
*/
class Solution 
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        queue<pair<string, int>> q;
        q.push({start, 1});
        while (!q.empty())
        {
            pair<string, int> front = q.front();
            q.pop();
            string word = front.first;
            for (size_t i = 0; i < word.size(); i++)
            {
                char before = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if(word[i] == c) continue;
                    word[i] = c;
                    if (word == end)
                        return front.second + 1;
                    if (dict.find(word) != dict.end())
                    {
                        q.push({word, front.second + 1});
                        dict.erase(word);
                    }
                }
                word[i] = before;
            }
        }
        return 0;
    }
};

/*
    Say the ladder is of length 'len', and each word branches out 'm' 
        new words.

    From one end, we have to generate O(m^len) branches. Yet from both 
        ends, we are only supposed to generate O(2m^(len/2)) braches. 
        So we are sqrt(m^len)/2 times faster.
*/
class Solution2 
{
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
    {
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        unordered_set<string> nextWords, prevWords;
        nextWords.insert(beginWord);
        prevWords.insert(endWord);
        
        int ladder = 2, len = (int)beginWord.length();
        while (!nextWords.empty() && !prevWords.empty())
        {
            if (nextWords.size() > prevWords.size())
                swap(nextWords, prevWords);
            unordered_set<string> temp;
            for (auto word : nextWords)
            {
                for (int p = 0; p < len; p++)
                {
                    char before = word[p];
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        if(word[p] == ch) continue;
                        word[p] = ch;
                        if (prevWords.find(word) != prevWords.end())
                            return ladder;
                        if (wordDict.find(word) != wordDict.end())
                        {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = before;
                }
            }
            swap(nextWords, temp);
            ladder++;
        }
        return 0;
    }
};

