#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 150001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
ll ne, be;

void dfs(int node, int par = -1)
{
    vis[node] = true;
    ne++;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            be++;
        }
        else
        {
            dfs(child, node);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    bool flag = false;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            be = 0;
            ne = 0;
            dfs(i);

            be /= 2;

            if (ne * (ne - 1) != 2 * (be + ne - 1))
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}