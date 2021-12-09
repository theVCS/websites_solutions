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

int n, k;
queue<int> q;
vector<int> arr[maxN];
int dist[maxN];

bool dfs(int node = 1, int par = -1, int d = 0)
{
    if (arr[node].size() == 1 && node!=1)
        return true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        if (dist[child] > d + 1)
        {
            if (dfs(child, node, d + 1))
                return true;
        }
    }

    return false;
}

void solve()
{
    cin >> n >> k;

    REP(i, 1, n)
    {
        arr[i].clear();
        dist[i] = INF;
    }

    REP(i, 1, k)
    {
        int a;
        cin >> a;
        q.push(a);
        dist[a] = 0;
    }

    REP(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        for (int child : arr[node])
        {
            if (dist[child] > dist[node] + 1)
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    // REP(i,1,n)cout<<dist[i]<<" ";
    // cout<<endl;
    
    if (dfs())
    {
        cout << "YES" << endl;
    }
    else
    {
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