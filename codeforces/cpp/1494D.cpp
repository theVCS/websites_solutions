#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 511
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
    int a, b, val;
};

int parent[maxN * maxN];
int ans[maxN * maxN];
vector<edge> arr;
vector<pii> ed;

bool cmp(edge a, edge b)
{
    return a.val < b.val;
}

int find(int a)
{
    if (parent[a] < 0)
        return a;
    else
        return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    REP(i, 1, maxN * maxN)
    parent[i] = -1;

    int n, dum;

    cin >> n;

    REP(i, 1, n + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> dum;

            if (i == j)
                ans[i] = dum;
            else if (i < j)
            {
                edge e;
                e.a = i, e.b = j, e.val = dum;
                arr.push_back(e);
            }
        }
    }

    sort(all(arr), cmp);
    int nu = n;

    for (edge e : arr)
    {
        int a = find(e.a);
        int b = find(e.b);

        if (a == b)
            continue;

        if (max(ans[a], ans[b]) == e.val)
        {
            if (ans[a] > ans[b])
            {
                merge(a, b);
                ed.push_back({b, a});
            }
            else
            {
                merge(b, a);
                ed.push_back({a, b});
            }

            continue;
        }

        nu++;
        ans[nu] = e.val;
        merge(nu, a);
        merge(nu, b);
        ed.push_back({a, nu});
        ed.push_back({b, nu});
    }

    cout << nu << endl;

    REP(i, 1, nu + 1)
    cout << ans[i] << " ";
    cout << endl;

    cout << find(1) << endl;

    for (pii e : ed)
        cout << e.first << " " << e.second << endl;

    return 0;
}