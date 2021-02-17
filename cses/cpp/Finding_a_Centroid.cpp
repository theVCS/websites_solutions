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
int subSize[maxN];

int dfs(int node, int par)
{
    subSize[node] = 1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        subSize[node] += dfs(child, node);
    }

    return subSize[node];
}

int cenCal(int node, int par, int n)
{
    for (int child : arr[node])
    {
        if (child == par)
            continue;

        if (subSize[child] > n / 2)
            return cenCal(child, node, n);
    }

    return node;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs(1, -1);

    cout << cenCal(1, -1, n);

    return 0;
}