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
vector<int> graph[maxN], revAdj[maxN];
int intime[maxN];
int dp[maxN];
bool vis[maxN];


void solve()
{
    cin >> n;

    REP(i, 1, n)
    graph[i].clear(), intime[i] = 0, dp[i] = 0, vis[i] = false, revAdj[i].clear();

    REP(i, 1, n)
    {
        int k;
        cin >> k;

        REP(j, 1, k)
        {
            int x;
            cin >> x;
            graph[x].push_back(i);
            revAdj[i].push_back(x);
            intime[i]++;
        }
    }

    queue<int> q;

    REP(i, 1, n)
    {
        if (intime[i] == 0)
            q.push(i), dp[i] = 1;
    }

    vector<int>vec;

    while (q.empty() == false)
    {
        int x = q.front();
        vis[x] = true;
        vec.push_back(x);

        q.pop();

        for (int node : graph[x])
        {
            intime[node]--;
            
            if (intime[node] == 0)
            {
                q.push(node);
            }
        }
    }

    REP(i,1,n)
    if(vis[i]==false)
    {
        cout<<-1<<endl;
        return;
    }

    int mx=-1;

    for(int ele: vec)
    {
        for(int node: revAdj[ele])
        {
            dp[ele]=max(dp[ele],dp[node]+(node>ele));
        }

        mx=max(mx,dp[ele]);
    }

    cout << mx << endl;
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