/*
	Given an array that represents elements of arithmetic progression 
		in order. One element is missing in the progression, find the 
		missing number.

	Examples:

		Input: arr[]  = {2, 4, 8, 10, 12, 14}
		Output: 6

		Input: arr[]  = {1, 6, 11, 16, 21, 31};
		Output: 26
*/

class Solution
{
private:
	int findMissing(vector<int> &vec, int b, int e, int diff)
	{
	    if (b >= e) return -1;
	    int m = b + (e - b) / 2;

	    if (vec[m + 1] - vec[m] != diff) return vec[m] + diff;
	    if (m > 0 && vec[m] - vec[m - 1] != diff) return vec[m - 1] + diff;
	    if (vec[m] == vec[0] + diff * m) return findMissing(vec, m + 1, e, diff);
	    return findMissing(vec, b, m - 1, diff);
	}
public:
	int findMissing(vector<int> &vec)
	{
	    if (vec.size() < 3) return -1;  //invalid
	    int diff = min(vec[1] - vec[0], vec[2] - vec[1]);
	    return findMissing(vec, 0, vec.size() - 1, diff);
	}	
};