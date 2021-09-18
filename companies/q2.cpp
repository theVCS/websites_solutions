#include <bits/stdc++.h>
using namespace std;

typedef int ll;
#define int long long

const int maxn = 5e5 + 5;
vector<pair<int, int>> graph[maxn];

int cost[1001][1001];
bool vis[1001][1001];
int n, m, k, a, b, c;

void djkstra()
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(a, 0)));
    cost[a][0] = 0;
    while (!pq.empty())
    {

        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();
        int curr_n = curr.second.first;
        int curr_s = curr.second.second;
        int cst = cost[curr_n][curr_s];

        for (int i = 0; i < graph[curr_n].size(); i++)
        {
            if (graph[curr_n][i].first == curr_n)
                continue;
            int c_cst = cst + graph[curr_n][i].second;
            if (cost[graph[curr_n][i].first][curr_s] == -1)
            {
                pq.push(make_pair(c_cst * (-1), make_pair(graph[curr_n][i].first, curr_s)));
                cost[graph[curr_n][i].first][curr_s] = c_cst;
            }
            else if (cost[graph[curr_n][i].first][curr_s] > c_cst)
            {
                cost[graph[curr_n][i].first][curr_s] = c_cst;
                pq.push(make_pair(c_cst * (-1), make_pair(graph[curr_n][i].first, curr_s)));
            }
            c_cst = cst;
            if (curr_s == k)
                continue;
            if (cost[graph[curr_n][i].first][curr_s + 1] == -1)
            {
                pq.push(make_pair(c_cst * (-1), make_pair(graph[curr_n][i].first, curr_s + 1)));
                cost[graph[curr_n][i].first][curr_s + 1] = c_cst;
            }
            else if (cost[graph[curr_n][i].first][curr_s + 1] > c_cst)
            {
                cost[graph[curr_n][i].first][curr_s + 1] = c_cst;
                pq.push(make_pair(c_cst * (-1), make_pair(graph[curr_n][i].first, curr_s + 1)));
            }
        }
    }

    long long ret = 2e18;
    for (int j = 0; j <= k; j++)
    {
        if (cost[b][j] == -1)
            continue;
        ret = min(ret, cost[b][j]);
    }

    if (ret == 2e18)
        cout << -1;
    else
        cout << ret << " ";
}

ll main()
{
    cin >> n >> a >> b >> k >> m >> c;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    memset(cost, -1, sizeof(cost));
    djkstra();
}
