#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int check(int x, int d)
{
    while (x)
    {
        if (x % 10 == d)
            return 1;
        x /= 10;
    }

    return 0;
}

int dp[110];

int fun(int index, int d)
{
    if (index == 110)
        return 0;
    else if(index < d)
        return 0;
    else if (dp[index] != -1)
        return dp[index];
    else
    {
        int f = check(index,d);

        REP(i, 1, index - 1)
        {
            if(f)break;
            int j = index - i;

            if (fun(i, d) && fun(j, d) && check(i, d) && check(j, d))
            {
                f = 1;
            }
        }

        return dp[index] = f;
    }
}

void solve()
{
    int q, d;
    cin >> q >> d;

    memset(dp, -1, sizeof(dp));

    REP(i, 1, q)
    {
        int x;
        cin >> x;

        if (x >= (10 * d + 9) || fun(x, d) || x % d == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}