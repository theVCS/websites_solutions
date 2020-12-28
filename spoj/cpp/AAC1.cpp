#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int dist[maxN];

void bfs(int node = 1)
{
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    vis[node] = true;

    while (!q.empty())
    {
        int currn = q.front();
        q.pop();

        for (int child : arr[currn])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dist[child] = 1 + dist[currn];
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

    while (t--)
    {
        cin >> n >> m;

        REP(i, 1, n + 1)
        {
            vis[i] = false;
            arr[i].clear();
        }

        REP(i, 0, m)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        bfs();

        cout << dist[n] << endl;
    }

    return 0;
}