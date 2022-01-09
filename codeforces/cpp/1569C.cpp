#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 200001
#define INF 1000000000
#define mod 998244353
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll fact[maxN + 15];
ll arr[maxN];

void init()
{
    fact[0] = 1;

    REP(i, 1, maxN + 10)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll binExp(ll a, ll p, ll m = mod)
{
    ll res = 1;
    a %= m;

    while (p)
    {
        if (p & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }

    return res;
}

ll ncr(int n, int r)
{
    ll v = fact[n];
    v *= binExp(fact[r], mod - 2);
    v %= mod;
    v *= binExp(fact[n - r], mod - 2);
    v %= mod;
    return v;
}

void solve()
{
    ll n;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + 1 + n);

    if (arr[n] == arr[n - 1])
    {
        cout << fact[n] << endl;
        return;
    }

    if (arr[n] - arr[n - 1] > 1)
    {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    int index = n - 1;

    while (index >= 1 && arr[index] == arr[n - 1])
    {
        cnt++;
        index--;
    }

    ll ans = fact[n];

    REP(i, cnt + 1, n)
    {
        ll v = ncr(i - 1, cnt);
        v *= fact[cnt];
        v %= mod;
        v *= fact[n - cnt - 1];
        v %= mod;
        ans -= v;
        ans += mod;
        ans %= mod;
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    init();

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}