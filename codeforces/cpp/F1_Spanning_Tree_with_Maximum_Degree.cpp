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
int indegree[maxN];
bool vis[maxN];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int child : arr[cur])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                cout << cur << " " << child << endl;
            }
            
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, nodeX, ind = 0;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        indegree[a]++, indegree[b]++;

        if (indegree[a] > ind)
        {
            ind = indegree[a];
            nodeX = a;
        }

        if (indegree[b] > ind)
        {
            ind = indegree[b];
            nodeX = b;
        }
    }

    bfs(nodeX);

    return 0;
}