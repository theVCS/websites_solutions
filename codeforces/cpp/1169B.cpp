#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 300001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int indegree[maxN];
map<int, vector<int>> checker;

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, cc = 0;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
            cc++;
        }
    }

    if (cc > 2)
    {
        cout << "NO";
        return 0;
    }

    REP(i, 1, n + 1)
    {
        checker[indegree[i]].push_back(i);
    }

    if (checker[1].size() == n - 2)
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";

    return 0;
}