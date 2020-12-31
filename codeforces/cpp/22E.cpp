#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int indegree[maxN];
vector<pair<int, int>> res;
bool vis[maxN];

void dfs(int node, int inn, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (vis[child])
        {
            res.push_back({inn, child});
        }
        else
        {
            dfs(child, inn, node);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dum, incounter = 0, cc = 0;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> dum;
        arr[i].push_back(dum);
        indegree[dum]++;
    }

    REP(i, 1, n + 1)
    {
        if (indegree[i] == 0)
        {
            dfs(i, i);
            incounter++;
        }
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i, i);
            cc++;
        }
    }

    int size = res.size();

    if (incounter || cc > 1)
    {
        cout << size << endl;

        REP(i, 0, size)
        {
            cout << res[i].second << " " << res[(i + 1) % size].first << endl;
        }
    }
    else
    {
        cout << 0;
    }
    

    return 0;
}