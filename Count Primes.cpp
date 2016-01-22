/*
    Count the number of prime numbers less than a non-negative number, n.
*/

//Sieve of Eratosthenes

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; ++i)
            if(isPrime[i])
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;

        int cnt = 0;
        for (int i = 2; i < n; ++i)
            cnt += isPrime[i];
        return cnt;
    }
};
