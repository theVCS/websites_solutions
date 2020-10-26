#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll a, b;

    cin >> t;

    while (t--)
    {
        cin >> a >> b;

        if (__gcd(a, b) == 1)
        {
            cout << a * b - a - b + 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}