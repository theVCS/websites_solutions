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

int n;
struct point
{
    int x, y;
} bag, obj[25];

int tim(point &a, point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int dp[1 << 24];
int path[1 << 24];

void solve()
{
    cin >> bag.x >> bag.y;

    cin >> n;

    REP(i, 0, n - 1)
    cin >> obj[i].x >> obj[i].y;

    REP(i, 1, (1 << n) - 1)
    dp[i] = INF;

    REP(bitmask, 0, (1 << n) - 1)
    {
        REP(i, 0, n - 1)
        {
            if (bitmask & (1 << i))
                continue;

            REP(j, 0, n - 1)
            {
                if (bitmask & (1 << j))
                    continue;

                int nmask = bitmask | (1 << i) | (1 << j);
                int val = dp[bitmask] + tim(bag, obj[i]) + tim(obj[i], obj[j]) + tim(obj[j], bag);

                if (dp[nmask] <= val)
                    continue;
                dp[nmask] = val;
                path[nmask] = bitmask;
            }

            break;
        }
    }

    int bitmask = (1<<n) - 1;
    cout << dp[bitmask] << endl;

    while (bitmask)
    {
        int nmask = path[bitmask];
        cout << 0 << " ";
        REP(i, 0, n - 1)
        if ((nmask ^ bitmask) & (1 << i))
            cout << i + 1 << " ";
        bitmask = nmask;
    }

    cout << 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}