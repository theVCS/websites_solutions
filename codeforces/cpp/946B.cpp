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

    ll n, m;

    cin >> n >> m;

    while (true)
    {
        if (m == 0 || n == 0)
        {
            break;
        }
        else if (n >= (2 * m))
        {
            n %= (2 * m);
        }
        else if (m >= (2 * n))
        {
            m %= (2 * n);
        }
        else
        {
            break;
        }
    }

    cout << n << " " << m;

    return 0;
}