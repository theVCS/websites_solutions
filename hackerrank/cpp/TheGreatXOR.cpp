#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll maxXOR(ll n)
{
    ll pos = 0, num = 0;
    for (int i = 63; i > -1; i--)
    {
        if (n & (1LL << i))
        {
            pos = i;
            break;
        }
    }

    for (int i = pos - 1; i > -1; i--)
    {
        if (!(n & (1LL << i)))
        {
            num += (1LL << i);
        }
    }

    return num;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    ll x;

    cin >> q;

    while (q--)
    {
        cin >> x;
        cout << maxXOR(x) << endl;
    }

    return 0;
}