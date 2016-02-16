class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int lower_bound(vector<int> &A, int target) {
        // write your code here
        int b = 0, e = (int)A.size();
        while (b < e)
        {
            int m = b + (e - b) / 2;
            if (A[m] < target) b = m + 1;
            else e = m;
        }
        return b;
    }
};
