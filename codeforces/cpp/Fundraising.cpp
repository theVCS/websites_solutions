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
#define INF 0x3f3f3f3f
#define endl "\n"
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

struct guests
{
    ll beauty, money, donation;
} guest[maxN];

bool cmp(guests a, guests b)
{
    if (a.beauty == b.beauty)
        return a.donation < b.donation;
    return a.beauty < b.beauty;
}

// implementing segment tree
vector<pair<ll, ll>> segTree[4 * maxN]; // first is the money of the person and second is the donation
vector<ll> cumSum[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back({guest[ss].money, guest[ss].donation});
        cumSum[si].push_back(guest[ss].donation);
    }
    else
    {
        int mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        int i = 0, j = 0;
        ll sum = 0;

        while (i < segTree[2 * si].size() && j < segTree[2 * si + 1].size())
        {
            if (segTree[2 * si][i].first < segTree[2 * si + 1][j].first)
            {
                sum += segTree[2 * si][i].second;
                cumSum[si].push_back(sum);
                segTree[si].push_back(segTree[2 * si][i]);
                i++;
            }
            else
            {
                sum += segTree[2 * si + 1][j].second;
                cumSum[si].push_back(sum);
                segTree[si].push_back(segTree[2 * si + 1][j]);
                j++;
            }
        }

        while (i < segTree[2 * si].size())
        {
            sum += segTree[2 * si][i].second;
            cumSum[si].push_back(sum);
            segTree[si].push_back(segTree[2 * si][i]);
            i++;
        }

        while (j < segTree[2 * si + 1].size())
        {
            sum += segTree[2 * si + 1][j].second;
            cumSum[si].push_back(sum);
            segTree[si].push_back(segTree[2 * si + 1][j]);
            j++;
        }
    }
}

ll query(int si, int ss, int se, int qs, int qe, ll val)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        pair<ll, ll> p = {val, 0};
        int index = lower_bound(all(segTree[si]), p) - segTree[si].begin();
        ll sum = cumSum[si][cumSum[si].size() - 1];
        if (index)
            sum = sum - cumSum[si][index - 1];
        return sum;
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe, val) + query(2 * si + 1, mid + 1, se, qs, qe, val));
}

void solve()
{
    int n;

    cin >> n;

    REP(i, 1, n + 1)
    cin >> guest[i].beauty >> guest[i].money >> guest[i].donation;

    sort(guest + 1, guest + 1 + n, cmp);

    build(1, 1, n);
    ll res = 0;

    REP(i, 1, n + 1)
    {
        cout << query(1, 1, n, i + 1, n, guest[i].money) + guest[i].donation << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}