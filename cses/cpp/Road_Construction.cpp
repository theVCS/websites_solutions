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
#define all(x) (x).begin(), (x).end()
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int parent[maxN];
int res, maxSize;

int find(int a)
{
    if (parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);

    if (a == b)
        return;

    if (parent[a] > parent[b])
        swap(a, b);

    parent[a] += parent[b];
    parent[b] = a;

    maxSize = min(maxSize, parent[a]);
    res--;
}

void solve()
{
    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, n + 1)
    parent[i] = -1;

    res = n, maxSize = -1;

    REP(i, 0, m)
    {
        cin >> a >> b;
        merge(a, b);
        cout << res << " " << maxSize * -1 << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}