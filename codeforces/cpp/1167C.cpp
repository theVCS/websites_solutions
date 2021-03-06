#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int dist[maxN], dis;
map<int,int>dum;

void dfs(int node, int root)
{
    vis[node] = true;
    dist[node] = root;
    dis++;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, root);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, a, b;

    cin >> n >> m;

    while (m--)
    {
        cin >> k;

        if (k)
        {
            cin >> a;
            k--;

            REP(i, 0, k)
            {
                cin >> b;
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
        }
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dis = 0;
            dfs(i, i);
            dum[i] = dis;
        }
    }

    REP(i, 1, n + 1)
    {
        cout << dum[dist[i]] << " ";
    }

    return 0;
}