#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool sieve[maxN];
vector<int> primes;

void init()
{
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!sieve[i])
        {
            for (int j = 2 * i; j < maxN; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    for (int i = 2; i < maxN; i++)
    {
        if (!sieve[i])
        {
            primes.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        int arr[n];

        REP(i, 0, n)
        cin >> arr[i];

        vector<ll> res(n, 1);

        REP(i, 0, n)
        {
            if (i != arr[i] - 1)
            {
                res[i] *= primes[i] * 1LL;
                res[arr[i] - 1] *= primes[i] * 1LL;
            }
            else if (res[i] == 1)
            {
                res[i] *= primes[i] * 1LL;
            }
        }

        REP(i, 0, n)
        cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}