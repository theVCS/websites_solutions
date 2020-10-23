#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<ll> primes;
bool arr[32000];

void init(int maxN = 31623)
{
    arr[0] = arr[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!arr[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                arr[j] = true;
            }
        }
    }

    for (ll i = 2; i <= maxN; i++)
    {
        if (!arr[i])
        {
            primes.push_back(i);
        }
    }

    // for(ll P : primes)
    // {
    //     cout<<P<<" ";
    // }
    // cout<<endl;
}

void run(ll l, ll u)
{
    int cnt = 0;
    bool rprimes[u - l + 1];
    memset(arr, true, u - l + 1);

    for (ll P : primes)
    {
        if (P * P <= u)
        {
            ll mul = (l / P) * P;

            if (mul < l)
            {
                mul += P;
            }

            for (ll i = mul; i <= u; i += P)
            {
                if (i != P)
                {
                    rprimes[i - l] = false;
                }
            }
        }
    }
    cout << endl;
    for (int i = l; i <= u; i++)
    {
        if (rprimes[i - l])
        {
            cout << i << endl;
        }
    }

    // for (ll i = l; i <= u - 2; i++)
    // {
    //     if (rprimes[i - l] && rprimes[i - l + 2])
    //     {
    //         cnt++;
    //     }
    // }
    cout << cnt << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, n;
    cin >> m >> n;
    init(sqrt(n) + 1);
    run(m, n);

    return 0;
}