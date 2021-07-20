#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

int n, m;
vector<pii> arr[50001];
int dis[50000];

void bfs()
{
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();

        for (pii child : arr[node.second])
        {
            int cost = max(0, child.second - node.first) + node.first;

            if (dis[child.first] > cost)
            {
                dis[child.first] = cost;
                pq.push({cost, child.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int a, b, c;

    cin >> n >> m;

    REP(i, m + 1, n)
    dis[i] = 1e9;

    REP(i, 1, m)
    {
        if (i <= n)
            dis[i] = 1e9;
        scanf("%d%d%d", &a, &b, &c);
        arr[a].push_back({b, c}), arr[b].push_back({a, c});
    }

    bfs();

    if (dis[n] == 1e9)
        printf("NOT POSSIBLE");
    else
        printf("%d", dis[n]);

    return 0;
}