#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct target
{
    ll x, y, t;
    double p;
} arr[maxN];
double dp[maxN];

bool check(target &b, target &a)
{
    ll d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    ll t = (a.t - b.t) * (a.t - b.t);
    return t >= d;
}

bool cmp(target &a, target &b)
{
    return a.t < b.t;
}

void solve()
{
    int N;
    cin >> N;

    REP(i, 1, N)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].t >> arr[i].p;
    }

    sort(arr+1,arr+1+N,cmp);

    double ans=arr[N].p;
    dp[N] = arr[N].p;

    RREP(i, N-1, 1)
    {
        double res = 0;

        REP(j, i+1, N)
        {
            if(check(arr[j],arr[i]))
            {
                res = max(dp[j],res);
            }
        }

        dp[i]=res+arr[i].p;
        ans=max(ans,dp[i]);
    }

    printd(ans);
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