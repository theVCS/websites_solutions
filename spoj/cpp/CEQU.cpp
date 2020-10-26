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

    int t, a, b, c, cnt = 1;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;

        if (c % (__gcd(a, b)) == 0)
        {
            cout << "Case " << cnt << ": Yes" << '\n';
        }
        else
        {
            cout << "Case " << cnt << ": No" << '\n';
        }
        cnt++;
    }

    return 0;
}