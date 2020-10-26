#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

class Solution
{
    bool primes[21];

public:
    Solution()
    {
        memset(primes, true, 21);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= 21; i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j < 21; j += i)
                {
                    primes[j] = false;
                }
            }
        }
    }

    int count(int n)
    {
        int cnt = 0;

        while (n)
        {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }

    int countPrimeSetBits(int L, int R)
    {
        int cnt = 0;

        for (int i = L; i <= R; i++)
        {
            if(primes[count(i)])
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}