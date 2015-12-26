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
    //We can make use of tuple as with C++11.
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
        bool operator()(group &g1, group &g2) {return g1.val > g2.val;}
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

//Record the maximun prime factor of each ugly number, and only multiply
//  it by the prime factor which is not less than the prime factor of the
//  ugly number. So we can avoid duplicates.
class Solution2
{
    //val, idx, prime factor
    //  val: the candidate ugly number
    //  idx: the index of the ugly number in res that is gonna to be multiplied
    //  prime factor: the prime factor of the candidate ugly number.
    using TIII = tuple<int, int, int>;
private:
    class myGreater
    {
    public:
        bool operator()(TIII &a, TIII &b) {return get<0>(a) > get<0>(b);}
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        priority_queue<TIII, vector<TIII>, myGreater> pq;
        vector<int> res(n, 1), max_factor(n, 1);
        res[0] = 1;
        
        for (auto &p : primes)
            pq.push(make_tuple(p, 1, p));
        
        for(int idx = 1; idx < n;)
        {
            auto tmp = pq.top();
            pq.pop();
            res[idx] = get<0>(tmp);
            max_factor[idx++] = get<2>(tmp);
            while (max_factor[get<1>(tmp)] > get<2>(tmp)) get<1>(tmp)++;
            pq.push(make_tuple(res[get<1>(tmp)] * get<2>(tmp), get<1>(tmp) + 1, get<2>(tmp)));
        }
        return res.back();
    }
};

//O(NK). This performs even better than the heap solution. I guess
//  it is because the primes is of small sizes. So it just doesn't 
//  matter much if it is K or log(K).
class Solution3
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        for(int i=1; i<n; i++)
        {
            for(int j = 0; j < primes.size(); j++) 
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
            for(int j = 0; j < primes.size(); j++) 
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
        }
        return ugly[n-1];
}
};