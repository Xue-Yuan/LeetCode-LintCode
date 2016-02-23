/*
    You are playing the following Flip Game with your friend: Given a string 
        that contains only these two characters: + and -, you and your friend 
        take turns to flip two consecutive "++" into "--". The game ends when 
        a person can no longer make a move and therefore the other person will 
        be the winner.

    Write a function to compute all possible states of the string after one 
        valid move.

    For example, given s = "++++", after one move, it may become one of the 
        following states:

            [
              "--++",
              "+--+",
              "++--"
            ]
            
    If there is no valid move, return an empty list [].
*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ret;
        int sz = s.size();
        for (int i = 0; i < sz-1; ++i)
        {
            string tmp = s;
            if ((s[i] == '+') && (s[i+1] == '+'))
            {
                tmp[i] = tmp[i+1] = '-';
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
