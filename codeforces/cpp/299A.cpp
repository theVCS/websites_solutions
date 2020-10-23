#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<ll> arr;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll dum, gcd;

    cin >> dum;
    gcd = dum;
    arr.push_back(gcd);
    n--;
    

    while (n--)
    {
        cin >> dum;

        gcd = __gcd(gcd, dum);
        arr.push_back(dum);
    }

    for (ll P : arr)
    {
        if (P == gcd)
        {
            cout << gcd;
            return 0;
        }
    }
    cout << -1;

    return 0;
}