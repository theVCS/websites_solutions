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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
 
vector<int> arr[maxN];
int parent[maxN], n;
int depth[maxN];
int intime[maxN], outime[maxN], timer;
 
void dfs(int node = 1, int par = 0, int d = 0)
{
    parent[node] = par;
    depth[node] = d;
    intime[node] = ++timer;
 
    for (int child : arr[node])
    {
        if (child == par)
            continue;
 
        dfs(child, node, d + 1);
    }
 
    outime[node] = ++timer;
}
 
bool isAnces(int par, int node)
{
    return intime[par] <= intime[node] && outime[par] >= outime[node];
}
 
bool query()
{
    int k, d = -1, node = 0, dum;
    vector<int> vec;
 
    cin >> k;
 
    REP(i, 0, k)
    {
        cin >> dum;
        vec.push_back(dum);
 
        if (d < depth[dum])
            d = depth[dum], node = dum;
    }
 
    for (int &e : vec)
    {
        if (e != node && parent[e] > 0)
        {
            e = parent[e];
        }
    }
 
    bool flag = true;
 
    for (int e : vec)
    {
        flag &= isAnces(e, node);
    }
 
    return flag;
}
 
void solve()
{
    int m, a, b;
 
    cin >> n >> m;
 
    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }
 
    dfs();
 
    while (m--)
    {
        if (query())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
 
    // cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    return 0;
}
