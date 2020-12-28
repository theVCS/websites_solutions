#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;
    cout << node << " ";

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    cout << node << " ";

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : arr[curr])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                cout << child << " ";
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, a, b;

    cin >> t;

    REP(j, 1, t + 1)
    {
        cin >> n;

        REP(i, 1, n + 1)
        {
            vis[i] = false;
            arr[i].clear();
        }

        REP(i, 1, n + 1)
        {
            cin >> a >> m;

            while (m--)
            {
                cin >> b;
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
        }

        cin >> a >> b;

        cout << "graph " << j << endl;

        while (a)
        {
            REP(i, 1, n + 1)
            {
                vis[i] = false;
            }

            if (b == 0)
            {
                dfs(a);
            }
            else
            {
                bfs(a);
            }
            cout << endl;
            cin >> a >> b;
        }
    }

    return 0;
}