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

int n, m;
char flg[501][501];
int dp[501][27][27];
char res[501][27][27][2];
int mem[501][27][27];

int val(char c)
{
    return (c - 'a') + 1;
}

int cost(int row, char odd, char even)
{
    if (mem[row][val(odd)][val(even)] != -1)
        return mem[row][val(odd)][val(even)];

    int c = 0;
    char arr[] = {even, odd};

    REP(j, 1, m)
    {
        if (flg[row][j-1] != arr[j & 1])
            c++;
    }

    return mem[row][val(odd)][val(even)] = c;
}

int newFlag(int row = 1, int odd = 0, int even = 0)
{
    if (row == n + 1)
        return 0;

    if (dp[row][odd][even] != -1)
        return dp[row][odd][even];

    int ans = INF;

    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = c1+1; c2 <= 'z'; c2++)
        {
            if (val(c1) != odd && val(c2) != even && ans > cost(row, c1, c2) + newFlag(row + 1, val(c1), val(c2)))
                ans = cost(row, c1, c2) + newFlag(row + 1, val(c1), val(c2)), res[row][odd][even][0] = c2, res[row][odd][even][1] = c1;

            if (val(c1) != even && val(c2) != odd && ans > cost(row, c2, c1) + newFlag(row + 1, val(c2), val(c1)))
                ans = cost(row, c2, c1) + newFlag(row + 1, val(c2), val(c1)), res[row][odd][even][0] = c1, res[row][odd][even][1] = c2;
        }
    }

    return dp[row][odd][even] = ans;
}

void printAns(int row = 1, int odd = 0, int even = 0)
{
    if (row == n + 1)
        return;

    REP(j, 1, m)
    cout << res[row][odd][even][j & 1];
    cout << endl;

    printAns(row + 1, val(res[row][odd][even][1]), val(res[row][odd][even][0]));
}

void solve()
{
    cin >> n >> m;

    REP(i, 1, n)
    {
        cin>>flg[i];

        REP(c1,0,26)
        REP(c2,0,26)
        dp[i][c1][c2]=mem[i][c1][c2]=-1;
    }

    cout << newFlag() << endl;
    printAns();
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