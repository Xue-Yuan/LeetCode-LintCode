/*
    Given an integer n, count the total number of digit 1 
        appearing in all non-negative integers less than or 
        equal to n.

    For example:
        Given n = 13,
        Return 6, because digit 1 occurred in the following 
        numbers: 1, 10, 11, 12, 13.
*/

/*
    First save the num of ones from 1 ~ 9, 1 ~ 99, 1 ~ 999, ...

    Take 321 as an example, (321) = (300) + (20) + (1),
        (300) = 3 * (1 ~ 99) + (hundred digit from (100 ~ 199)),
        (20) = 2 * (1 ~ 9) + (10 ~ 19).

    Sepcial case exists when the most significant digit is 1.
        Say we have 123, then
        (123) = 1 * (1 ~ 99) + (hundred digit from (100 ~ 123)) + (23)
*/
class Solution 
{
private:
	int countDigi(int n)
	{
		int digi_num = 0;
		while(n)
		{
			digi_num++;
			n /= 10;
		}
		return digi_num;
	}
public:
    int countDigitOne(int n) 
    {
    	if(n < 1) return 0;
        if(n < 10) return 1;
        int digi_num = countDigi(n);
        vector<int> cache(digi_num + 1, 0);
        /*
        cache[1]: 1 ~ 9
        cahce[2]: 1 ~ 99
        cache[3]: 1 ~ 999
        cache[4]: 1 ~ 9999
        */
        cache[1] = 1;
        int tmp = 10;
        for(int i = 2; i <= digi_num; ++i)
        {
            cache[i] = 10 * cache[i - 1] + tmp;
            tmp *= 10;
        }
        tmp = pow(10, digi_num - 1);
        int num_one = 0;
        while(digi_num > 0 && n)
        {
        	int q = n / tmp;
        	int r = n % tmp;
        	if(q == 1)	//if 123, 1 * (1 ~ 99) + (100 ~ 123)
        		num_one += q * cache[digi_num - 1] + r + 1;
        	else		//if 321, 3 * (1 ~ 99) + (100 ~ 199)
        				//(100 ~ 199) = 100
        		num_one += q * cache[digi_num - 1] + pow(10, digi_num - 1);
        	n = r;
        	digi_num = countDigi(n);   //We need to compute digits again
	        tmp = pow(10, digi_num - 1);
        }
        return num_one;
    }
};

// Taken from https://leetcode.com/discuss/44281/4-lines-o-log-n-c-java-python
class Solution2
{
public:
    int countDigitOne(int n) 
    {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) 
        {
            int a = n/m, b = n%m;
            ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return ones;
    }
};
