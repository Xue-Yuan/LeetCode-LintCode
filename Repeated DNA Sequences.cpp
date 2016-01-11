/*
    All DNA is composed of a series of nucleotides abbreviated as 
        A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, 
        it is sometimes useful to identify repeated sequences within 
        the DNA.

    Write a function to find all the 10-letter-long sequences 
        (substrings) that occur more than once in a DNA molecule.

    For example,

        Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

    Return:
        ["AAAAACCCCC", "CCCCCAAAAA"].
*/

//Only 4 letters needed, so we can use just 20 bits to represent 
//  a 10-letter-long sequence thus saving time and spaces.
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.length() < 11) return {};
        
        bitset<20> mole[26];
        mole['A' - 'A'] = 0x0; mole['C' - 'A'] = 0x1; 
        mole['G' - 'A'] = 0x2; mole['T' - 'A'] = 0x3;
        
        bitset<20> x;
        int i = 0;
        for (; i < 10; ++i)
            x = (x << 2) | mole[s[i] - 'A'];
        
        unordered_map<bitset<20>, int> m;
        m[x] = 1;
        vector<string> res;
        for (; i < s.length(); ++i)
        {
            x = (x << 2) | mole[s[i] - 'A'];
            if (m[x]++ == 1)
                res.push_back(s.substr(i - 9, 10));
        }
        return res;
    }
};
