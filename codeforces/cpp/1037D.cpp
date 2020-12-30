#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int dist[maxN];

void bfs(int node)
{
    vis[node] = true;
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
                q.push(child);
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

    int n, a, b, m;

    cin >> n;
    m = n - 1;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bfs(1);

    cin >> a;
    cout << dist[a] << " ";
    REP(i, 1, n)
    {
        cin >> b;
        cout << dist[b] << " ";

        if (dist[a] > dist[b])
        {
            cout << "No";
            return 0;
        }

        a = b;
    }

    cout << "Yes";

    return 0;
}