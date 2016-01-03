#include <iostream>
#include <string>

using namespace std;

/*
    Given a nested list of integers, returns the sum of all integers in 
        the list weighted by their depth * For example, given the list 
        {{1,1},2,{1,1}} the function should return 10 (four 1's at depth 2, 
        one 2 at depth 1) * Given the list {1,{4,{6}}} the function should 
        return 27 (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3)
*/

//Simple version, just to show the idea.

class Solution
{
public:
    int NestedIntegerWeightedSum(const string &str)
    {
        int sum = 0, level = 1;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '{') level++;
            else if (str[i] == '}') level--;
            else sum += (str[i] - '0') * level;
        }
        return sum;
    }
};

int main()
{
    cout << Solution{}.NestedIntegerWeightedSum("1{4{6}}") << endl;
    return 0;
}