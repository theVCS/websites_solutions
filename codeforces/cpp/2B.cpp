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

pii cnt(int n)
{
    int cnt2 = 0, cnt5 = 0;

    if (n == 0)
        return {INF, INF};

    while (n % 2 == 0 || n % 5 == 0)
    {
        if (n % 2 == 0)
            n /= 2, cnt2++;
        if (n % 5 == 0)
            n /= 5, cnt5++;
    }

    return {cnt2, cnt5};
}

int n;
pii dp[1002][1002];

struct element
{
    int pow2, pow5;
} arr[1001][1001];

pii fun(int x = 1, int y = 1)
{
    if (dp[x][y].first != -1)
        return dp[x][y];

    if (x > n || y > n)
        return dp[x][y] = {INF, INF};

    if (x == n && y == n)
        return dp[x][y] = {arr[x][y].pow2, arr[x][y].pow5};

    pii res = {INF, INF};
    pii ans1 = fun(x + 1, y);
    pii ans2 = fun(x, y + 1);
    res.first = min(ans1.first, ans2.first);
    res.second = min(ans1.second, ans2.second);

    return dp[x][y] = {res.first + arr[x][y].pow2, res.second + arr[x][y].pow5};
}

int val(pii d, int i)
{
    if (i == 0)
        return d.first;
    else
        return d.second;
}

void printPath(int x, int y, int index)
{
    if (x == n && y == n)
        return;

    if (val(dp[x + 1][y], index) <= val(dp[x][y + 1], index) && x < n)
    {
        cout << 'D';
        printPath(x + 1, y, index);
    }
    else
    {
        cout << 'R';
        printPath(x, y + 1, index);
    }
}

void solve()
{
    cin >> n;

    bool flag = false;
    int x = -1, y = -1;

    REP(i, 1, n)
    REP(j, 1, n)
    {
        int ele;
        cin >> ele;
        if (ele == 0)
            flag = true, x = i, y = j;
        pii p = cnt(ele);
        arr[i][j].pow2 = p.first;
        arr[i][j].pow5 = p.second;
    }

    memset(dp, -1, sizeof(dp));

    pii ans = fun();

    int res = -1;
    int index = -1;

    if (ans.first < ans.second)
    {
        res = ans.first;
        index = 0;
    }
    else
    {
        res = ans.second;
        index = 1;
    }

    if(flag && res>1)
    {
        cout<<1<<endl;

        int ix=1, iy=1;

        while (ix!=x)
        {
            cout<<'D';
            ix++;
        }
        
        while (iy!=n)
        {
            cout<<'R';
            iy++;
        }

        while (ix!=n)
        {
            cout<<'D';
            ix++;
        }

        return;
    }

    cout << res << endl;
    printPath(1, 1, index);
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