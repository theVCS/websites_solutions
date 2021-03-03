#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

set<int> arr[maxN];
bool vis[maxN];
ll cnt;

void dfs(int node, int par = -1)
{
    vis[node] = true;
    bool flag = true;
    int leaf = 1;

    for (int child : arr[node])
    {
        if (par != -1 && arr[child].find(par) == arr[child].end())
            flag = false;

        if (vis[child])
            continue;

        dfs(child, node);
        leaf = 0;
    }

    if (flag && !leaf && par != -1)
        cnt++;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].insert(b), arr[b].insert(a);
    }

    REP(i, 1, n + 1)
    {
        if (vis[i] == false)
            dfs(i);
    }

    cout << cnt;

    return 0;
}