#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
ll ar[150005], br[150005];
vector<ll> primeFactors;

void primefact(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            primeFactors.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    bool flag;
    cin >> n;
    ll as = 1, bs = 1;

    REP(i, 0, n)
    {
        cin >> ar[i];
        cin >> br[i];
    }

    primefact(ar[0]);
    primefact(br[0]);

    for (int i = 0; i < primeFactors.size(); i++)
    {
        flag = true;
        for (int j = 0; j < n; j++)
        {
            if ((ar[j] % primeFactors[i]) && (br[j] % primeFactors[i]))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << primeFactors[i];
            return 0;
        }
    }
    cout << "-1";
    return 0;
}