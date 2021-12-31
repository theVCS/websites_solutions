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

void solve()
{
    ll n;
    cin >> n;
    vector a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0, f = 0;
    vector vis(n + 1, 0), v2(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] <= n && vis[a[i]] == 0)
        {
            vis[a[i]] = 1;
            v2[i] = 1;
        }
    }
    vector<int> v, v3;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] != 1)
        {
            v.push_back(i);
        }
        if (v2[i] == 0)
        {
            v3.push_back(a[i]);
        }
    }
    ll k = 0;
    for (ll i = 0; i < v3.size(); i++)
    {
        ll tmp = v3[i] / 2 + 1;
        if (v3[i] - tmp >= v[k])
        {
            ans++;
            k++;
        }
        f = 1;
        break;
    }

    if (f)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
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