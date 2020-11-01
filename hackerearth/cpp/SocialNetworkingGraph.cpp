#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
vector<int> arr[maxN];
bool vis[maxN];
int dis[maxN];

int bfs(int src, int t)
{
    int cnt = 0;
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
            if (vis[child] == false)
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[curr] + 1;

                if (dis[child] == t)
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b, m, s, t;

    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    cin >> m;

    while (m--)
    {
        int cnt = 0;
        cin >> s >> t;
        memset(vis, false, maxN);
        cout << bfs(s, t) << endl;
    }

    return 0;
}