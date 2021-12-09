#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int arrSize = 10001;
map<int, int> mp;
ll rev[arrSize];
int arr[arrSize];

template <class T>
class SegmentTree
{
    int n;
    vector<T> count, mode, sum, mxCount;

public:
    SegmentTree() {}

    void resize(int N)
    {
        n = N;
        sum.assign(4 * n, 0);
        count.assign(4 * n, 0);
        mode.assign(4 * n, 0);
        mxCount.assign(4 * n, 0);
    }

    ll query(int si, int ss, int se, int c)
    {
        if (ss == se)
        {
            return rev[ss];
        }
        else
        {
            int mid = (ss + se) / 2;

            if (c <= count[2 * si])
                return query(2 * si, ss, mid, c);
            else
                return query(2 * si + 1, mid + 1, se, c - count[2 * si]);
        }
    }

    ll getMean()
    {
        return sum[1] / count[1];
    }

    ll getMedian()
    {
        if (count[1] % 2)
            return query(1, 1, n, (count[1] / 2) + 1);
        else
            return (query(1, 1, n, (count[1] / 2)) + query(1, 1, n, (count[1] / 2) + 1)) / 2;
    }

    ll getMode()
    {
        return mode[1];
    }

    void _update_(int si, int ss, int se, int qi, T val, T fre)
    {
        if (ss == se)
        {
            sum[si] = fre * val;
            count[si] = fre;
            mode[si] = val;
            mxCount[si] = fre;
        }
        else
        {
            int mid = (ss + se) / 2;

            if (qi <= mid)
                _update_(2 * si, ss, mid, qi, val, fre);
            else
                _update_(2 * si + 1, mid + 1, se, qi, val, fre);

            sum[si] = sum[2 * si] + sum[2 * si + 1];
            count[si] = count[2 * si] + count[2 * si + 1];

            if (mxCount[2 * si] > mxCount[2 * si + 1])
                mode[si] = mode[2 * si], mxCount[si] = mxCount[2 * si];
            else if (mxCount[2 * si] < mxCount[2 * si + 1])
                mode[si] = mode[2 * si + 1], mxCount[si] = mxCount[2 * si + 1];
            else
                mode[si] = max(mode[2 * si], mode[2 * si + 1]), mxCount[si] = mxCount[2 * si];
        }
    }

    void update(int qi, T val, T fre)
    {
        _update_(1, 1, n, qi, val, fre);
    }
};

template <class T>
class MO
{
    struct Query
    {
        int l, r, index;
        ll order;

        Query(int _l, int _r, int _index)
        {
            l = _l;
            r = _r;
            index = _index;
            order = gilbertOrder(l, r, 21, 0);
        }

        inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
        {
            if (pow == 0)
            {
                return 0;
            }
            int hpow = 1 << (pow - 1);
            int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
            seg = (seg + rotate) & 3;
            const int rotateDelta[4] = {3, 0, 0, 1};
            int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
            int nrot = (rotate + rotateDelta[seg]) & 3;
            int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
            int64_t ans = seg * subSquareSize;
            int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
            ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
            return ans;
        }
    };

    int n, q;
    T res;
    vector<T> fre;
    vector<ll> ans[3];
    vector<Query> Q;
    SegmentTree<ll> segTree;

public:
    MO() {}

    // N -> no of elements, Q -> no of queries, R -> range of elements
    MO(int N, int Q, int R)
    {
        n = N;
        q = Q;

        res = 0;
        fre.assign(R + 1, 0);
        ans[0].resize(Q + 1);
        ans[1].resize(Q + 1);
        ans[2].resize(Q + 1);
        segTree.resize(N);
    }

    void addQuery(int l, int r, int index)
    {
        Q.push_back(Query(l, r, index));
    }

    void add(int index)
    {
        ll ele = arr[index];
        ++fre[ele];
        segTree.update(ele, rev[ele], fre[ele]);
    }

    void remove(int index)
    {
        ll ele = arr[index];
        --fre[ele];
        segTree.update(ele, rev[ele], fre[ele]);
    }

    void processQuery()
    {
        sort(all(Q), [](const Query &lhs, const Query &rhs)
             { return lhs.order < rhs.order; });

        for (int i = 0, L = 1, R = 0; i < q; i++)
        {
            while (R < Q[i].r)
                add(++R);
            // cout<<"Prince"<<endl;
            while (L > Q[i].l)
                add(--L);
            while (R > Q[i].r)
                remove(R--);
            while (L < Q[i].l)
                remove(L++);

            ans[0][Q[i].index] = segTree.getMean();
            ans[1][Q[i].index] = segTree.getMedian();
            ans[2][Q[i].index] = segTree.getMode();
        }
    }

    void showAns()
    {
        REP(i, 1, q)
        {
            cout << ans[0][i] << " " << ans[1][i] << " " << ans[2][i] << endl;
        }
    }
};

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        mp[arr[i]];
    }

    int timer = 0;

    for (auto &e : mp)
        e.second = ++timer;

    REP(i, 1, n)
    {
        int temp = arr[i];
        arr[i] = mp[arr[i]];
        rev[arr[i]] = temp;
    }

    int q;
    cin >> q;

    MO<int> mo(n, q, n);

    REP(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        l++, r++;
        mo.addQuery(l, r, i);
    }

    mo.processQuery();
    mo.showAns();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}