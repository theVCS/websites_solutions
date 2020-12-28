#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int check[maxN];

void dfs(int node, int c)
{
    vis[node] = true;
    check[node] = c;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, c);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, a, b;
    string s;
    bool flag;

    cin >> t;

    while (t--)
    {
        vector<pair<int, int>> ne;

        cin >> n >> m;

        flag = true;
        for (int i = 0; i < n + 1; i++)
        {
            arr[i].clear();
            vis[i] = false;
            check[i] = 0;
        }

        while (m--)
        {
            cin >> a >> s >> b;

            if (s == "=")
            {
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
            else
            {
                ne.push_back({a, b});
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, i);
            }
        }

        for (pair<int, int> e : ne)
        {
            if (check[e.first] == check[e.second])
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}