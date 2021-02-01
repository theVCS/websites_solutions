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

int n, k, depth;
vector<int> arr[maxN];
vector<int> dep[maxN];
int indegree[maxN];
// int subSize[maxN];
int parent[maxN];
int dept[maxN][2];

bool cmp(int a, int b)
{
    if (indegree[a] < indegree[b])
    {
        return true;
    }
    return false;
}

void dfs(int node = 1, int par = -1, int d = 0)
{
    dep[d].push_back(node);
    // int size = 1;
    depth = max(depth, d);
    parent[node] = par;
    dept[node][0] = dept[node][1] = d;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, d + 1);
        }
    }
    // subSize[node] = size - 1;
    // return size;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n >> k;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
        indegree[a]++, indegree[b]++;
    }

    dfs();

    REP(i, 0, depth + 1)
    {
        sort(dep[i].begin(), dep[i].end(), cmp);
    }

    ll res = 0;

    for (int i = depth; i > 0 && k > 0; i--)
    {
        if (k <= dep[i].size())
        {
            res += k * i * 1LL;

            for (int node : dep[i])
            {
                if (k == 0)
                {
                    break;
                }

                int diff = dept[node][0] - dept[node][1];
                int nd = dept[parent[node]][0];

                dep[nd].erase(remove(dep[nd].begin(), dep[nd].end(), parent[node]), dep[nd].end());
                nd--;
                dept[parent[node]]--;
                dep[nd].push_back(parent[node]);

                k--;

                // cout << node << " ";
            }
        }
        else
        {
            res += dep[i].size() * i * 1LL;

            for (int node : dep[i])
            {
                int old_level = dept[parent[node]];

                dep[nd].erase(remove(dep[nd].begin(), dep[nd].end(), parent[node]), dep[nd].end());

                nd--;
                dept[parent[node]]--;

                dep[nd].push_back(parent[node]);

                // cout << node << " ";
            }

            k -= dep[i].size();
        }
    }

    cout << res;

    return 0;
}