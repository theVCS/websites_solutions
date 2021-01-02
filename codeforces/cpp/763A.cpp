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
int subSize[maxN], subCol[maxN], col[maxN];

pair<set<int>, int> dfs(int node)
{
    set<int> s;
    s.insert(col[node]);
    vis[node] = true;
    int size = 1;
    pair<set<int>, int> res;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            res = dfs(child);
            set_union(res.first.begin(), res.first.end(), s.begin(), s.end(), inserter(s, s.begin()));
            size += res.second;
        }
    }

    subCol[node] = s.size();
    subSize[node] = size;

    return {s, size};
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    pair<set<int>, int> s = dfs(1);

    REP(i, 1, n + 1)
    {
        if (subSize[i] == subCol[i])
        {
            cout << "NO"
        }
        
    }

    return 0;
}