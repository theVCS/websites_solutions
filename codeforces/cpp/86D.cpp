#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int N = 200001;

int arr[N], fre[1000001];
ll ans[N], res;

struct query
{
    int l, r, index, lblk;
} q[N];

bool cmp(query a, query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.r < b.r);
}

void add(int index)
{
    res -= 1LL * fre[arr[index]] * fre[arr[index]] * arr[index] * 1LL;
    fre[arr[index]]++;
    res += 1LL * fre[arr[index]] * fre[arr[index]] * arr[index] * 1LL;
}

void remove(int index)
{
    res -= 1LL * fre[arr[index]] * fre[arr[index]] * arr[index];
    fre[arr[index]]--;
    res += 1LL * fre[arr[index]] * fre[arr[index]] * arr[index];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    const int blk = sqrt(n);

    REP(i, 1, n + 1)
    cin >> arr[i];

    REP(i, 1, m + 1)
    {
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
        q[i].lblk = q[i].l / blk;
    }

    sort(q + 1, q + m + 1, cmp);

    for (int i = 1, L = 1, R = 0; i < m + 1; i++)
    {
        while (L < q[i].l)
            remove(L++);
        while (L > q[i].l)
            add(--L);
        while (R < q[i].r)
            add(++R);
        while (R > q[i].r)
            remove(R--);

        ans[q[i].index] = res;
    }

    REP(i, 1, m + 1)
    {
        cout << ans[i] << endl;
    }

    return 0;
}