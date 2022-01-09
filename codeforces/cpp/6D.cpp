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

int n, a, b;
int health[11];
vector<int> res;
int dp[11][17][17];
int path[11][17][17];
int hea[11][17][17];

// minHits for killing archer from i-n after hitting prev archer with j hits left with prevHealth
int minHits(int i, int j, int prevHealth)
{
    if (i == n)
        return j > 0 ? INF : 0;
    else if (dp[i][j][prevHealth] != -1)
        return dp[i][j][prevHealth];
    else
    {
        int ans = INF;
        int currHealth = health[i] - b * j;

        REP(x, 0, 16)
        {
            if (prevHealth > x * b)
                continue;
            int redHealth = currHealth - x * a;
            redHealth = max(0, redHealth);
            int k = x + minHits(i + 1, x, redHealth);
            if (ans > k)
                ans = k, path[i][j][prevHealth] = x, hea[i][j][prevHealth] = redHealth;
        }

        return dp[i][j][prevHealth] = ans;
    }
}

void getResult(int i, int j, int prevHealth)
{
    if (i == n)
        return;

    int m = path[i][j][prevHealth];
    getResult(i + 1, m, hea[i][j][prevHealth]);

    while (m--)
        res.push_back(i);
}

void solve()
{
    cin >> n >> a >> b;

    REP(i, 1, n)
    cin >> health[i], health[i]++;

    // killing 1 and nth archers in beginning
    while (health[1] > 0)
    {
        health[1] -= b;
        health[2] -= a;
        health[3] -= b;
        res.push_back(2);
    }

    health[1] = max(health[1], 0);
    health[2] = max(health[2], 0);
    health[3] = max(health[3], 0);

    while (health[n] > 0)
    {
        health[n] -= b;
        health[n - 1] -= a;
        health[n - 2] -= b;
        res.push_back(n - 1);
    }

    health[n] = max(health[n], 0);
    health[n - 1] = max(health[n - 1], 0);
    health[n - 2] = max(health[n - 2], 0);
    // killed 1 and nth archers

    memset(dp, -1, sizeof(dp));
    int x = minHits(2,0,0);
    getResult(2, 0, 0);
    cout << res.size() << endl;

    for (int e : res)
        cout << e << " ";
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