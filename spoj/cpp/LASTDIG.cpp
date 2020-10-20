#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll lastdig(ll a, ll n)
{
    ll res = 1;
    a %= 10;

    while (n)
    {
        if (n % 2)
        {
            n--;
            res = (res * a) % 10;
        }
        n /= 2;
        a = (a * a) % 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    ll a, b;

    while (t--)
    {
        cin >> a >> b;
        cout << lastdig(a, b) << endl;
    }

    return 0;
}