/*
	Follow up for H-Index: What if the citations array is sorted in ascending 
		order? Could you optimize your algorithm?
*/

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        int ret = 0, len = (int)citations.size();
		int b = 0, e = len;
		while (b < e)
		{
		    int m = b + (e - b) / 2, remain = len - m;
		    if (citations[m] >= remain) e = m;
		    else b = m+1;
		    ret = max(min(citations[m], remain), ret);      
		}
		return ret;
    }
};
