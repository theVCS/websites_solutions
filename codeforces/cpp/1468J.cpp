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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct edge
{
    int a, b, w;
};

vector<edge> arr;

bool cmp(edge a, edge b)
{
    return (a.w < b.w);
}

int parent[maxN];

int find(int a)
{
    if (parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    if (parent[a] > parent[b])
        swap(a, b);

    parent[a] += parent[b];
    parent[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, k, a, b, c;

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        REP(i, 0, n + 1)
        parent[i] = -1;

        arr.clear();

        REP(i, 0, m)
        {
            edge e;
            cin >> a >> b >> c;
            e.a = a, e.b = b, e.w = c;
            arr.push_back(e);
        }

        sort(all(arr), cmp);
        ll res = 0;

        for (edge e : arr)
        {
            int a = find(e.a), b = find(e.b);

            if (a == b)
                continue;

            merge(a, b);

            res += max(0LL, (e.w - k) * 1LL);
        }

        if (res == 0)
        {
            res = INT_MAX;

            for (edge e : arr)
                res = min(res, abs(k - e.w) * 1LL);
        }

        cout << res << endl;
    }

    return 0;
}