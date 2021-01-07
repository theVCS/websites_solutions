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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int cnt;

void dfs(int node, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            cnt = 0;
            return;
        }
        else
        {
            dfs(child, node);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    int res = 0;

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cnt = 1;
            dfs(i);
            res += cnt;
        }
    }

    cout << res;

    return 0;
}