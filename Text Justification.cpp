/*
    Given an array of words and a length maxWidth, format the text 
        such that each line has exactly maxWidth characters and is 
        fully (left and right) justified.

    You should pack your words in a greedy approach; that is, 
        pack as many words as you can in each line. Pad extra 
        spaces ' ' when necessary so that each line has exactly 
        maxWidth characters.

    Extra spaces between words should be distributed as evenly 
        as possible. If the number of spaces on a line do not 
        divide evenly between words, the empty slots on the maxWidth
        eft will be assigned more spaces than the slots on the 
        right.

    For the last line of text, it should be left justified and 
        no extra space is inserted between words.

    For example,
        words: ["This", "is", "an", "example", "of", "text", "justification."]
        maxWidth: 16.

    Return the formatted lines as:
        [
           "This    is    an",
           "example  of text",
           "justification.  "
        ]
*/

//Taken from https://github.com/leetcoders/LeetCode/blob/master/TextJustification.h
//  Truly elegent code. Wish one day I could write something like this.
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int i = 0;
        while (i < words.size())
        {
            int length = (int)words[i].size();
            int j = i + 1;
            while (j < words.size() && length + words[j].size() + (j-i) <= maxWidth)
                length += words[j++].size();
            // build line
            string s(words[i]);
            bool isLastLine = (j == words.size());
            bool oneWord = (j == i + 1);
            /*
            int average = (isLastLine || oneWord) ? 1 : (maxWidth - length) / (j - i - 1);
            int extra = (isLastLine || oneWord) ? 0 : (maxWidth - length) % (j - i - 1);
            */
            int average = isLastLine || oneWord ? 1 : (maxWidth - length) / (j - i - 1);
            int extra = isLastLine || oneWord ? 0 : (maxWidth - length) % (j - i - 1);
            for (int k = i + 1; k < j; ++k)
            {
                s.append(extra-- > 0 ? average + 1 : average, ' ');
                s.append(words[k]);
            }
            s.append(maxWidth - s.size(), ' ');
            // push line
            res.push_back(s);
            i = j;
        }
        return res;
    }
};

class Solution2
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        if (words.empty()) return {};
        
        int idx = 0, beg = 0;
        vector<string> ret;
        while (idx < words.size())
        {
            string line = "";
            int cnt = 0, total = 0;
            while (idx < words.size() && total + words[idx].size() <= maxWidth)
            {
                total += words[idx++].size() + 1;
                cnt++;
            }
            if (cnt > 1)
            {
                total = 0;
                for (int i = beg; i < idx; ++i)
                    total += words[i].size();
                int even_space = (maxWidth - total) / (cnt - 1);
                int odd_space = (maxWidth - total) % (cnt - 1);
                //The last word of a line not followed by spaces.
                for (int i = beg; i < idx - 1; ++i)
                {
                    line += words[i] + ((odd_space-- > 0) ? " " : "");
                    line.append(even_space, ' ');
                }
                line += words[idx - 1];
            }
            //one word a line
            else
            {
                line += words[idx - 1];
                line.append(maxWidth - line.size(), ' ');
            }
            ret.push_back(line);
            beg = idx;
        }
        //The last line
        string &last = *--ret.end();
        istringstream in(last);
        last = "";
        for (string tmp; in >> tmp;)
            last += tmp + " ";
        if (last.back() == ' ') last.pop_back();
        last.append(maxWidth - last.size(), ' ');
        return ret;
    }
};