#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int blk = 700;
int n, m, q;
int f[300];
vector<int> arr[maxN];
// bool vis[maxN];
int cc;

void dfs(int node, int l, int r, map<int,bool>vis = {})
{
    vis[node] = true;
    cc++;

    for (int child : arr[node])
    {
        if (!vis[child] && child >= l && child <= r)
        {
            dfs(child, l, r);
        }
    }
}

void init(int n)
{
    for (int i = 1; i <= n; i+=blk)
    {
        cc = 0;
        
    }
    
}

struct query
{
    int l, r;
};
query Q[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> q;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for (int i = 0; i < q; i++)
        {
            cin >> Q[i].l >> Q[i].r;
        }
    }

    return 0;
}