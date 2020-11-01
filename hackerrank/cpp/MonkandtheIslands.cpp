#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
vector<int> arr[maxN];
bool vis[maxN];
int dis[maxN];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

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
                dis[child] = dis[curr] + 1;
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
        for (int i = 0; i < maxN; i++)
        {
            arr[i].clear();
            vis[i] = false;
        }
        

        cin >> n >> m;
        while (m--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        bfs(1);

        cout << dis[n] << endl;
    }

    return 0;
}