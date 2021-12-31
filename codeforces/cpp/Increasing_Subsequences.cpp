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
#define mod 5000000
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

template <class T>
class FenwickTree2D
{
    int n, m;
    vector<vector<T>> BIT;

public:
    FenwickTree2D() {}

    FenwickTree2D(int N, int M)
    {
        n = N;
        m = M;
        BIT.resize(n + 1);

        for (vector<T> &vec : BIT)
            vec.assign(m + 1, 0);
    }

    void resize(int N, int M)
    {
        n = N;
        m = M;
        BIT.resize(n + 1);

        for (vector<T> &vec : BIT)
            vec.assign(m + 1, 0);
    }

    T _query_(int x, int y)
    {
        T sum = 0;

        for (int i = x; i > 0; i -= (i & -i))
        {
            sum += BIT[i][y];
            sum %= mod;
        }

        return sum;
    }

    void update(int x, int y, T val)
    {
        for (int i = x; i <= n; i += (i & -i))
        {
            BIT[i][y] += val;
            BIT[i][y] %= mod;
        }
    }
};

int arr[10001];
map<int, int> mp;
ll pre[10001][51];

void solve()
{
    int n, k;
    cin >> n >> k;

    REP(i, 1, n)
    {
        cin >> arr[i];
        mp[arr[i]];
    }

    int timer = 0;
    for (auto &e : mp)
        e.second = ++timer;

    FenwickTree2D<ll> ft(n, k);
    ll ans = 0;

    REP(i, 1, n)
    {
        arr[i] = mp[arr[i]];
        if(arr[i]==arr[i-1])continue;
        ft.update(arr[i], 1, 1-pre[arr[i]][1]);
        pre[arr[i]][1] = 1;

        REP(j, 2, k)
        {
            ll val = ft._query_(arr[i] - 1, j - 1);
            ll dx = (val-pre[arr[i]][j]+mod) % mod;
            pre[arr[i]][j] = val;
            ft.update(arr[i], j, dx);
            if (j == k)
                ans += dx, ans %= mod;
        }
    }

    cout << ans;
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