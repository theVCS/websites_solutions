#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 100001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
ll height[maxN];
ll cost[maxN];

ll f(ll k)
{
    ll ans = 0;

    REP(i, 1, n)
    ans += cost[i] * abs(height[i] - k);

    return ans;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
        cin >> height[i];
    REP(i, 1, n)
        cin >> cost[i];

    ll l = 0, r = 10000;
    ll mn = 1e18;

    while (l <= r)
    {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;

        ll c1 = f(m1);
        ll c2 = f(m2);

        mn = min(mn, c1);
        mn = min(mn, c2);

        if (c1 < c2)
            r = m2 - 1;
        else if (c1 > c2)
            l = m1 + 1;
        else
            l = m1 + 1, r = m2 - 1;
    }

    cout << mn << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}