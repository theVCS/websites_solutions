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

    ll t, a, b, g;

    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        g = __gcd(a, b);
        cout << g << " " << (a * b) / g << endl;
    }

    return 0;
}