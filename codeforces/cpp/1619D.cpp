#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 50001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct frin
{
    int shop, hap;

    frin(int s, int h)
    {
        shop = s, hap = h;
    }
};
vector<frin> arr[maxN];

bool cmp(frin &a, frin &b)
{
    return a.hap > b.hap;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    REP(i, 1, n)
    arr[i].clear();

    REP(shop, 1, m)
    {
        REP(fri, 1, n)
        {
            int hap;
            cin >> hap;
            arr[fri].push_back(frin(shop, hap));
        }
    }

    int shop[m + 2] = {0}, shopCnt = 0;
    int prefix[n + 2];
    int suffix[n + 2];
    prefix[0]=INF;

    REP(fri, 1, n)
    {
        sort(all(arr[fri]), cmp);
        prefix[fri] = min(prefix[fri - 1], arr[fri][0].hap);
        if (++shop[arr[fri][0].shop] == 1)
            shopCnt++;
    }


    // cout<<shopCnt<<endl;

    if (shopCnt <= n - 1)
    {
        cout << prefix[n] << endl;
        return;
    }

    suffix[n+1]=INF;

    RREP(i, n, 1)
    {
        suffix[i] = min(arr[i][0].hap, suffix[i+1]);
        // cout<<suffix[i]<<endl;
    }

    int ans = 0;

    REP(i, 1, n)
    {
        --shop[arr[i][0].shop];

        int val = 0;

        for (frin shp : arr[i])
        {
            if (shop[shp.shop])
            {
                val = shp.hap;
                break;
            }
        }

            
        val = min({val, prefix[i - 1], suffix[i + 1]});
        cout<<val<<endl;
        ans = max(ans, val);

        ++shop[arr[i][0].shop];
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

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}