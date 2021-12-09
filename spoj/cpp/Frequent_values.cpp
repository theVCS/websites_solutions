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

const int arrSize = 100001;
int arr[arrSize];
int mn, mx;

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
    vector<T> fre, ans, ff;
    vector<Query> Q;

public:
    MO() {}

    // N -> no of elements, Q -> no of queries, R -> range of elements
    MO(int N, int Q, int R)
    {
        n = N;
        q = Q;
        res = 0;
        fre.assign(R + 1, 0);
        ff.assign(R + 1, 0);
        ans.resize(Q + 1);
    }

    void resize(int N, int Q, int R)
    {
        n = N;
        q = Q;
        res = 0;
        fre.assign(R + 1, 0);
        ans.resize(Q + 1);
    }

    void addQuery(int l, int r, int index)
    {
        Q.push_back(Query(l, r, index));
    }

    void add(int index)
    {
        ll ele = arr[index];
        ele = ele - mn + 1;
        ff[fre[ele]]--;
        ++fre[ele];
        ff[fre[ele]]++;
        res = max(res, fre[ele]);
    }

    void remove(int index)
    {
        ll ele = arr[index];
        ele = ele - mn + 1;
        if(res==fre[ele] && ff[fre[ele]]==1)res--;
        ff[fre[ele]]--;
        --fre[ele];
        ff[fre[ele]]++;
    }

    void processQuery()
    {
        sort(all(Q), [](const Query &lhs, const Query &rhs)
             { return lhs.order < rhs.order; });

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

            ans[Q[i].index] = res;
        }
    }

    void showAns()
    {
        REP(i, 1, q)
        {
            cout << ans[i] << endl;
        }
    }
};

void solve()
{
    while (true)
    {
        int n, q;
        cin >> n;

        if (n == 0)
            return;

        cin >> q;

        mn = INF;
        mx = -INF;

        REP(i, 1, n)
        {
            cin >> arr[i];
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }

        MO<int> mo(n, q, mx - mn + 10);

        REP(i, 1, q)
        {
            int a, b;
            cin >> a >> b;
            mo.addQuery(a, b, i);
        }

        mo.processQuery();
        mo.showAns();
    }
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