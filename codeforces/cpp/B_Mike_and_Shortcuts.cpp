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
int dist[maxN], parent[maxN];
bool vis[maxN];

void bfs(int node = 1, int par = 1, int d = 0)
{
    vis[node] = true;
    dist[node] = 0;
    parent[node] = par;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : arr[curr])
        {
            if (!vis[child])
            {
                vis[child] = true;
                dist[child] = 1 + dist[curr];
                parent[child] = par;
                q.push(child);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dum;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> dum;

        if (i != dum)
        {
            arr[i].push_back(dum);
            arr[dum].push_back(i);
        }
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            arr[i].push_back(i - 1);
            arr[i - 1].push_back(i);
            bfs(i, i - 1);
        }
    }

    REP(i, 0, n + 1)
    vis[i] = false;
    
    bfs();

    cout << 0 << " ";

    for (int i = 2; i < n + 1; i++)
    {
        cout << dist[i] << " ";
        // if (parent[i] == 0)
        // {
        // }
        // else
        // {
        //     cout << dist[parent[i]] + (i - parent[i]) << " ";
        // }
    }

    return 0;
}