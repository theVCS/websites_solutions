#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n, g, dum;
    cin >> t;

    while (t--)
    {
        cin >> n;

        cin >> g;
        n--;

        while (n--)
        {
            cin >> dum;
            g = __gcd(g, dum);
        }

        if (g == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}