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

vector<int> arr[maxN], trans[maxN];
vector<int> order, SCC;
bool vis[maxN], vis1[maxN];

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
    order.push_back(node);
}

void dfs1(int node)
{
    vis1[node] = true;

    for (int child : trans[node])
    {
        if (!vis1[child])
        {
            dfs1(child);
        }
    }
    SCC.push_back(node);
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
        arr[a].push_back(b);
        trans[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    REP(i, 1, n + 1)
    {
        if (!vis1[order[n - i]])
        {
            dfs1(order[n - i]);

            if (SCC.size() > 1)
            {
                for (int ele : SCC)
                {
                    vis[ele] = false;
                }
            }

            SCC.clear();
        }
    }

    REP(i, 1, n + 1)
    {
        cout << !vis[i] << " ";
    }

    return 0;
}