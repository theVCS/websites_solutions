#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000009
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 300001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int fib[maxN + 10];

void init(int n)
{
    fib[0] = 0;
    fib[1] = 1;

    REP(i, 2, n + 1)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
}

int arr[maxN];
int segTree[4 * maxN];
vector<int> lazy[maxN * 4];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        arr[ss] = 0;
    }
    else
    {
        int mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        segTree[si] = (segTree[si * 2] + segTree[2 * si + 1]) % mod;
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (!lazy[si].empty())
    {
        for (int left : lazy[si])
        {
            segTree[si] = (segTree[si] + (fib[se - left + 3] - fib[ss - left + 2] + mod) % mod) % mod;

            if (ss != se)
                lazy[2 * si].push_back(left), lazy[2 * si + 1].push_back(left);
        }

        lazy[si].clear();
    }

    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe)) % mod;
}

void update(int si, int ss, int se, int qs, int qe)
{
    if (!lazy[si].empty())
    {
        for (int left : lazy[si])
        {
            segTree[si] = (segTree[si] + (fib[se - left + 3] - fib[ss - left + 2] + mod) % mod) % mod;

            if (ss != se)
                lazy[2 * si].push_back(left), lazy[2 * si + 1].push_back(left);
        }

        lazy[si].clear();
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si] = (segTree[si] + (fib[se - qs + 3] - fib[ss - qs + 2] + mod) % mod) % mod;

        if (ss != se)
            lazy[2 * si].push_back(qs), lazy[2 * si + 1].push_back(qs);

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);

    segTree[si] = (segTree[2 * si] + segTree[2 * si + 1]) % mod;
}

int main(int argc, char const *argv[])
{
    int n, m, code, a, b;

    scanf("%d %d", &n, &m);

    init(n + 2);

    REP(i, 1, n + 1)
    scanf("%d", arr + i);

    build(1, 1, n);

    while (m--)
    {
        scanf("%d %d %d", &code, &a, &b);

        if (code == 1)
        {
            update(1, 1, n, a, b);
        }
        else
        {
            printf("%d\n", query(1, 1, n, a, b));
        }
    }

    return 0;
}