#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 140000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll segTree[maxN * 4];

void build(int si, int ss, int se, bool &flag)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        flag = true;
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid, flag);
        build(2 * si + 1, mid + 1, se, flag);

        if (flag)
        {
            segTree[si] = segTree[2 * si] | segTree[2 * si + 1];
            flag = false;
        }
        else
        {
            segTree[si] = segTree[2 * si] ^ segTree[2 * si + 1];
            flag = true;
        }
    }
}

void update(int si, int ss, int se, int qi, bool &flag)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        flag = true;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi, flag);
    else
        update(2 * si + 1, mid + 1, se, qi, flag);

    if (flag)
    {
        segTree[si] = segTree[2 * si] | segTree[2 * si + 1];
        flag = false;
    }
    else
    {
        segTree[si] = segTree[2 * si] ^ segTree[2 * si + 1];
        flag = true;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, p;
    ll b;
    bool flag = false;

    cin >> n >> m;

    int N = pow(2, n);

    REP(i, 1, N + 1)
    cin >> arr[i];

    build(1, 1, N, flag);

    while (m--)
    {
        cin >> p >> b;
        arr[p] = b;
        update(1, 1, N, p, flag);
        cout << segTree[1] << endl;
    }

    return 0;
}