#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int subSize[maxN];

int dfs(int node, int par = -1)
{
    int size = 1;

    for (int child : arr[node])
    {
        if (child != par)
        {
            size += dfs(child, node);
        }
    }
    subSize[node] = size;
    return size;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, root = 1, res = 0;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> a;
        arr[a].push_back(i);
        arr[i].push_back(a);
        vis[i] = false;
    }

    REP(i, 0, n)
    {
        if (vis[i] == false)
        {
            root = i;
            break;
        }
    }

    subSize[root] = dfs(root);

    cin >> m;

    while (m--)
    {
        
    }
    

    return 0;
}