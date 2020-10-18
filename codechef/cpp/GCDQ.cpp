#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i, a, b) for (int i = a; i < b; i++)

int pre[100005], suff[100005];

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t, arr[100005], n, q, l, r;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        REP(i, 0, n)
        {
            cin >> arr[i];
        }

        REP(i, 1, n + 1)
        {
            pre[i] = gcd(arr[i - 1], pre[i - 1]);
        }

        for (int i = n; i > 0; i--)
        {
            suff[i] = gcd(arr[i - 1], suff[i + 1]);
        }

        REP(i, 0, q)
        {
            cin >> l >> r;
            cout << gcd(pre[l - 1], suff[r + 1]) << endl;
        }
    }

    return 0;
}