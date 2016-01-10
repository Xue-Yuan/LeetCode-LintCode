/*
	There is an integer array which has the following features:

		The numbers in adjacent positions are different.
		A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
	
	We define a position P is a peek if:

		A[P] > A[P-1] && A[P] > A[P+1]
	
	Find a peak element in this array. Return the index of the peak.

	Example
		Given [1, 2, 1, 3, 4, 5, 7, 6]

		Return index 1 (which is number 2) or 6 (which is number 7)

	Note
		The array may contains multiple peeks, find any of them.
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if (A.size() < 3) return -1;
        int b = 0, e = (int)A.size() - 1;
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (A[m - 1] < A[m] && A[m] > A[m + 1]) return m;
            if (A[m] < A[m - 1]) e = m;
            else b = m;
        }
        return -1;
    }
};
