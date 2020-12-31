#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 2001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN], enemy[maxN], ele;
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;
    ele.push_back(node);

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m, a, b;

    cin >> n >> k;

    while (k--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    cin >> m;

    while (m--)
    {
        cin >> a >> b;
        enemy[a].push_back(b);
        enemy[b].push_back(a);
    }

    int res = 0;
    bool flag;

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            ele.clear();
            flag = true;
            dfs(i);

            for (int per : ele)
            {
                for (int ene : enemy[per])
                {
                    for (int fri : ele)
                    {
                        if (ene == fri)
                        {
                            flag = false;
                            break;
                        }
                        if (!flag)
                        {
                            break;
                        }
                    }
                    if (!flag)
                    {
                        break;
                    }
                }
            }

            if (flag)
            {
                res = max(res, int(ele.size()));
            }
            
        }
    }

    cout << res;

    return 0;
}