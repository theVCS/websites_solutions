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

    int n;
    ll k, res;

    while (scanf("%d", &n) && n)
    {
        res = 1;

        while (n--)
        {
            cin >> k;

            if (res % k == 0 || k % res == 0)
            {
                res = max(res, k);
            }
            else
            {
                res = (k * res) / __gcd(k, res);
            }
        }
        cout << res << endl;
    }

    return 0;
}