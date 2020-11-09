/*
nice problem --- https://codeforces.com/problemset/problem/520/B
*/


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

void graphBuilder()
{
    REP(i, 1, maxN)
    {
        if (i > 1)
        {
            arr[i].push_back(i - 1);
            // arr[i - 1].push_back(i);
        }

        if (2 * i < maxN)
        {
            arr[i].push_back((2 * i));
            // arr[2 * i].push_back(i);
        }
    }
}

void bfs(int n)
{
    queue<int> q;
    vis[n] = true;
    q.push(n);
    dist[n] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : arr[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dist[child] = 1 + dist[curr];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    graphBuilder();

    int n, m;

    cin >> n >> m;

    bfs(n);

    cout << dist[m];

    return 0;
}