/*
    Validate if a given string is numeric.

    Some examples:
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    
    Note: It is intended for the problem statement to be ambiguous. 
        You should gather all requirements up front before implementing 
        one.
*/

//Taken from http://blog.csdn.net/kenden23/article/details/18696083
//  The hardest part is to gather the rules.

/*
    After 'e' or 'E', no more 'e's or 'E's or dicimals.
    "3." and ".3" are both considered valid.
*/
class Solution
{
public:
    bool isNumber(string s)
    {
        enum InputType
        {
            INVALID,        // 0 Include: Alphas, '(', '&' ans so on
            SPACE,          // 1
            SIGN,           // 2 '+','-'
            DIGIT,          // 3 numbers
            DOT,            // 4 '.'
            EXPONENT,       // 5 'e' 'E'
        };
        int transTable[][6] =
        {
        // INVA SPA SIG  DI  DO EXP
            -1,  0,  4,  1,  2, -1, //0 initial state, leading spaces
            -1,  8, -1,  1,  3,  5, //1 digits after initial
            -1, -1, -1,  3, -1, -1, //2 dot only
            -1,  8, -1,  3, -1,  5, //3 dot and digits
            -1, -1, -1,  1,  2, -1, //4 sign only
            -1, -1,  7,  6, -1, -1, //5 exp occurs
            -1,  8, -1,  6, -1, -1, //6 digits after exp
            -1, -1, -1,  6, -1, -1, //7 sign after exp
            -1,  8, -1, -1, -1, -1  //8 trailing spaces
        };
        int state = 0;
        for (auto &c : s)
        {
            InputType input = INVALID;
            if (c == ' ') input = SPACE;
            else if (c == '+' || c] == '-') input = SIGN;
            else if (isdigit(c)) input = DIGIT;
            else if (c == '.') input = DOT;
            else if (c == 'e' || c == 'E') input = EXPONENT;
            state = transTable[state][input];
            if (state == -1) return false;
        }
        return state == 1 || state == 3 || state == 6 || state == 8;
    }
};

//This is not solution2. Just a simplified version, without exponent.
class Solution2
{
public:
    bool validNumber(const string &str)
    {
        enum inputType{INVALID, DIGIT, DOT, SIGN, SPACE};
        vector<vector<int>> states
        {// inv  dig dot sig spa
            {-1,  1,  2,  4,  0}, //0 initial
            {-1,  1,  3, -1,  5}, //1 digit no dots, with or without signs in the beginning.
            {-1,  3, -1, -1, -1}, //2 just dot
            {-1,  3, -1, -1,  5}, //3 dot & digits
            {-1,  1,  2, -1, -1}, //4 just sign
            {-1, -1, -1, -1,  5}  //5 trailing spaces
        };

        int state = 0;
        for (auto &c : str)
        {
            inputType input = INVALID;
            if (c == '+' || c == '-') input = SIGN;
            else if (c == '.') input = DOT;
            else if (c == ' ') input = SPACE;
            else if (isdigit(c)) input = DIGIT;
            state = states[state][input];
            if (state == -1) return false;
        } 
        return state == 1 || state == 3 || state == 5;
    }
};
