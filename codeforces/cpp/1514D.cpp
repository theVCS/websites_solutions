#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 300001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN], fre[1000001], res, ans[maxN], ff[maxN];
const int blk = 900;

struct query
{
    int l, r, index, lblk;
} Q[maxN];

bool cmp(query a, query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.r < b.r);
}

void add(int index)
{
    int ele = arr[index];
    ff[fre[ele]]--;

    if (++fre[ele] > res)
        res = fre[ele];

    ff[fre[ele]]++;
}

void remove(int index)
{
    int ele = arr[index];

    if (ff[fre[ele]] == 1 && res == fre[ele])
    {
        res = fre[ele] - 1;
    }

    ff[fre[ele]]--;
    --fre[ele];
    ff[fre[ele]]++;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    REP(i, 1, n)
    cin >> arr[i];

    REP(i, 0, q - 1)
    {
        cin >> Q[i].l >> Q[i].r;
        // Q[i].l++, Q[i].r++;
        Q[i].index = i;
        Q[i].lblk = Q[i].l / blk;
    }

    sort(Q, Q + q, cmp);

    for (int i = 0, L = 1, R = 0; i < q; i++)
    {
        while (R < Q[i].r)
            add(++R);
        while (L > Q[i].l)
            add(--L);
        while (R > Q[i].r)
            remove(R--);
        while (L < Q[i].l)
            remove(L++);

        if (res <= (Q[i].r - Q[i].l + 2) / 2)
            ans[Q[i].index] = 1;
        else
            ans[Q[i].index] = 2 * res - (Q[i].r - Q[i].l + 1);
        // ans[Q[i].index] = res;
    }

    REP(i, 0, q - 1)
    cout << ans[i] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}