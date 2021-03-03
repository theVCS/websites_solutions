#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int parent[maxN];
int endCyc, nodeX;

bool dfs(int node, int par = -1)
{
    vis[node] = true;
    parent[node] = par;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            endCyc = child;
            nodeX = node;
            return true;
        }
        else
        {
            if (dfs(child, node))
                return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    bool flag = true;

    REP(i, 1, n + 1)
    {
        if (flag == false)
            break;

        if (vis[i] == false)
        {
            if (dfs(i))
            {
                vector<int> path;

                path.push_back(endCyc);
                while (nodeX != endCyc)
                {
                    path.push_back(nodeX);
                    nodeX = parent[nodeX];
                }
                path.push_back(nodeX);

                cout << path.size() << endl;
                for (int e : path)
                    cout << e << " ";

                flag = false;
            }
        }
    }

    if (flag)
        cout << "IMPOSSIBLE";

    return 0;
}