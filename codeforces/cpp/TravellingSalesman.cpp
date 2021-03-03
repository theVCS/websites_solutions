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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

struct edge
{
    int a, b, c;
} arr[maxN];

bool cmp(edge a, edge b)
{
    return a.c < b.c;
}

int par[maxN];

int find(int a)
{
    if (par[a] < 0)
        return a;
    else
        return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    if (par[a] > par[b])
        swap(a, b);

    par[a] += par[b];
    par[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n, m, a, b;

        cin >> n >> m;

        REP(i, 0, n + 1)
        par[i] = -1;

        REP(i, 0, m)
        cin >> arr[i].a >> arr[i].b >> arr[i].c;

        sort(arr, arr + m, cmp);
        int res;

        REP(i, 0, m)
        {
            int para = find(arr[i].a);
            int parb = find(arr[i].b);

            if (para != parb)
            {
                res = arr[i].c;
                merge(para, parb);
            }
        }

        cout << res << endl;
    }

    return 0;
}