/*
    Write a program to find the nth super ugly number.

    Super ugly numbers are positive numbers whose all prime factors 
        are in the given prime list primes of size k. For example, 
        [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence 
        of the first 12 super ugly numbers given primes = 
        [2, 7, 13, 19] of size 4.

    Note:
        (1) 1 is a super ugly number for any given primes.
        (2) The given numbers in primes are in ascending order.
        (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/
class Solution
{
private:
    struct group
    {
        int val;
        int factor;
        int index;
        group(int v, int f, int i):val(v), factor(f), index(i){}
    };
    class myGreater
    {
    public:
        bool operator()(group &g1, group &g2)
        {
            return g1.val > g2.val;
        }
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> ugly(n);
        ugly[0] = 1;
        priority_queue<group, vector<group>, myGreater> pq;
        
        for (auto &p : primes)
            pq.push({p, p , 0});
        
        int cnt = 1;
        while (cnt < n)
        {
            auto tmp = &pq.top();
            while (tmp->val == ugly[cnt - 1])
            {
                pq.push({tmp->factor * ugly[tmp->index + 1], tmp->factor, tmp->index + 1});
                pq.pop();
                tmp = &pq.top();
            }
            ugly[cnt++] = tmp->val;
            pq.push({tmp->factor * ugly[tmp->index + 1], tmp->factor, tmp->index + 1});
            pq.pop();
        }

        return ugly.back();
    }
};