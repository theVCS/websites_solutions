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

vector<int> arr[maxN];
int col[maxN];
bool vis[maxN];

bool dfs(int node, int c = 0)
{
    vis[node] = true;
    col[node] = c;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            if (!dfs(child, c ^ 1))
            {
                return false;
            }
        }
        else
        {
            if (col[child] == col[node])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    vector<pii> edge;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        edge.push_back({a, b});
    }

    REP(i, 1, n + 1)
    if (!vis[i])
    {
        if (!dfs(i))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << endl;
    REP(i, 0, m)
    cout << (col[edge[i].first] < col[edge[i].second]);

    return 0;
}