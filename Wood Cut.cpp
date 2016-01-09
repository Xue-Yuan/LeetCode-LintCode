/*
    Given n pieces of wood with length L[i] (integer array). Cut them 
        into small pieces to guarantee you could have equal or more 
        than k pieces with the same length. What is the longest length 
        you can get from the n pieces of wood? Given L & k, return the 
        maximum length of the small pieces.

    Example
        For L=[232, 124, 456], k=7, return 114.

    Note
        You couldn't cut wood into float length.
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.empty()) return 0;
        
        int b = 1, e, res = 0;
        e = *max_element(L.begin(), L.end());
        while (b <= e)
        {
            int cnt = 0;
            int m = b + (e - b) / 2;
            for (auto &l : L)
                cnt += l / m;
            if (cnt < k) e = m - 1;
            else
            {
                res = max(res, m);
                b = m + 1;
            }
        }
        return res;
    }
};