#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (ll i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, prod, temp;
    cin >> n;
    ll arr[n];

    REP(i, 0, n)
    {
        prod = 1;
        cin >> m;
        while (m--)
        {
            cin >> temp;
            prod *= temp;
        }
        arr[i] = prod;
    }

    temp = arr[0];
    REP(j, 1, n)
    {
        temp = __gcd(temp, arr[j]);
    }

    cout<<temp % 1000000007;
    return 0;
}