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
bool vis[maxN], hasBridge;
int intime[maxN], low[maxN], timer;

void dfs(int node = 1, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);

            if (intime[node] < low[child])
            {
                hasBridge = true;
                return;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, q;

    cin >> n >> m >> q;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs();

    while (q--)
    {
        cin >> a >> b;
    }

    if (hasBridge)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    return 0;
}