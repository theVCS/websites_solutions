#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 200001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
int par[maxN];
int per[maxN];
vector<int> arr[maxN];
int val[maxN];
int root;
int ans[maxN];

bool dfs(int node, int par = -1, int d = 0)
{
    int k = val[node] - d;
    // cout<<node<<" "<<k<<endl;
    if (k <= 0 && node != root)
        return false;

    ans[node] = k;
    bool flag = true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        if (dfs(child, node, d + k) == false)
            return false;
    }

    return true;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> par[i];
        arr[i].clear();
    }

    REP(i, 1, n)
    {
        cin >> per[i];
        val[per[i]] = i - 1;

        if (i != par[i])
        {
            arr[i].push_back(par[i]);
            arr[par[i]].push_back(i);
        }
        else
            root = i;
    }

    if (dfs(root) == false)
    {
        cout << -1 << endl;
        return;
    }

    REP(i, 1, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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