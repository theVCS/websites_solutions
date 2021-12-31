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
int arr[501], brr[501];
int dp[501][501];

int fun(int ai, int pos)
{
    if (ai == n + 1)
        return 0;
    else if (dp[ai][pos] != -1)
        return dp[ai][pos];
    else
    {
        int index = -1;

        REP(i, pos + 1, m)
        if (brr[i] == arr[ai] && brr[pos] < arr[ai])
        {
            index = i;
            break;
        }

        if (index == -1)
        {
            return dp[ai][pos] = fun(ai + 1, pos);
        }
        else
        {
            return dp[ai][pos] = max(1 + fun(ai + 1, index), fun(ai + 1, pos));
        }
    }
}

void solve()
{
    cin >> n;
    REP(i, 1, n)
    cin >> arr[i];

    cin >> m;
    REP(i, 1, m)
    cin >> brr[i];

    brr[0]=-1;

    memset(dp, -1, sizeof(dp));
    cout << fun(1, 0) << endl;

    vector<int> res;
    int ai = 1, pos = 0;

    while (ai <= n && pos <= m)
    {
        int index = -1;

        REP(i, pos + 1, m)
        if (brr[i] == arr[ai] && brr[pos] < arr[ai])
        {
            index = i;
            break;
        }

        if (index == -1)
        {
            ai++;
        }
        else
        {
            if (fun(ai, pos) == fun(ai + 1, pos))
                ai++;
            else
                res.push_back(arr[ai]), ai++, pos = index;
        }
    }

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