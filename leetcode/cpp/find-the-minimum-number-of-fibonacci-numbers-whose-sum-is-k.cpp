#define ll long long int
#define mod 1000000007
#define maxN 1000000001

class Solution
{
private:
    vector<ll> fib;
    int total;

public:
    Solution()
    {
        fib.push_back(0);
        total = 0;

        ll a = 1;
        ll b = 1;
        ll temp;

        while (b <= maxN)
        {
            fib.push_back(b);
            temp = a;
            a = b;
            b = temp + a;
        }
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int findMinFibonacciNumbers(ll k)
    {
        while (k)
        {
            for (ll i = 1; i < fib.size(); i++)
            {
                if (fib[i] > k)
                {
                    total++;
                    k -= fib[i - 1];
                    break;
                }
            }
        }
        return total;
    }
};
