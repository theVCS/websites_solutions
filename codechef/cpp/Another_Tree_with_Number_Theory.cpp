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
int parent[maxN];
int multiple[maxN];

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

void init(int node, int par = -1)
{
    parent[node] = par;
    int leaf = 1, cc = 0, l = 1;

    for (int child : arr[node])
    {
        if (child != par)
        {
            init(child, node);
            leaf = 0;
            cc++;
            l = lcm(l, multiple[child]);
        }
    }

    if (leaf)
        multiple[node] = 1;
    else
        multiple[node] = l * cc;
}

int dfs(int v, int work)
{
    if (work % multiple[v] == 0)
        return 0;
    else
    {
        int childCount = arr[v].size();

        if (v != 1)
            childCount--;

        if (work % childCount)
            return work;

        work /= childCount;

        int cnt = 0;

        for (int child : arr[v])
        {
            if (child != parent[v])
            {
                cnt += dfs(child, work);
            }
        }

        return cnt;
    }
}

int main(int argc, char const *argv[])
{
    int n, q, a, v, w;

    scanf("%d", &n);

    REP(i, 2, n + 1)
    {
        scanf("%d", &a);
        arr[a].push_back(i), arr[i].push_back(a);
    }

    init(1);

    scanf("%d", &q);

    while (q--)
    {
        scanf("%d %d", &v, &w);
        printf("%d\n", dfs(v, w));
    }

    return 0;
}