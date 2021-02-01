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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int N = 1e5 + 1;
int arr[N], k, res, ans[N], n, m, XOR[N];
bool use[1000001];
vector<int> pairs[N];

void init()
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i; j < n + 1; j++)
        {
            if ((XOR[j] ^ XOR[i - 1]) == k)
            {
                pairs[i].push_back(j);
            }
        }
    }
}

struct query
{
    int l, r, lblk, index;
} q[N];

bool cmp(query a, query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.r < b.r);
}

void add(int index)
{
    res += pairs[index].size();
}

void remove(int index)
{
    res -= pairs[index].size();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    const int blk = sqrt(n);

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        XOR[i] = XOR[i - 1] ^ arr[i];
    }

    init();

    REP(i, 1, n + 1)
    {
        for (int child : pairs[i])
            cout << child << " ";
        cout << endl;
    }

    REP(i, 1, m + 1)
    {
        cin >> q[i].l >> q[i].r;
        q[i].index = i, q[i].lblk = q[i].l / blk;
    }

    sort(q + 1, q + 1 + m, cmp);

    for (int i = 1, L = 1, R = 0; i < m + 1; i++)
    {
        while (L < q[i].l)
            remove(L++);
        while (L > q[i].l)
            add(++L);
        while (R < q[i].r)
            add(++R);
        while (R > q[i].r)
            remove(R--);

        ans[q[i].index] = res;
    }

    REP(i, 1, m + 1)
    cout << ans[i] << endl;

    return 0;
}