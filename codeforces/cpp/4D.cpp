#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 5001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;

struct envelope
{
    int w, h, index;
} arr[maxN], card;

bool cmp(envelope &a, envelope &b)
{
    return (a.w == b.w) ? (a.h < b.h) : (a.w < b.w);
}

int ft[maxN];
int dp[maxN];
int par[maxN];
int heightPar[maxN];
map<int, int> mp;

void solve()
{
    cin >> n;
    cin >> card.w >> card.h;

    int index = 1;

    REP(i, 1, n)
    {
        cin >> arr[index].w >> arr[index].h;
        arr[index].index = i;

        if (arr[index].w > card.w && arr[index].h > card.h)
            mp[arr[index].h], index++;
    }

    n = index-1;

    if(n==0)
    {
        cout<<0<<endl;
        return;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    int timer = 0;

    for (auto &e : mp)
        e.second = ++timer;

    REP(i, 1, n)
    arr[i].h = mp[arr[i].h];

    // REP(i,1,n)cout<<arr[i].w<<" "<<arr[i].h<<endl;

    int MX=0,INDEX=-1;

    REP(i, 1, n)
    {
        int mx = 0, p = -1;

        REP(j, 1, arr[i].h - 1)
        {
            if (arr[i].w == arr[heightPar[j]].w)
                continue;

            if (mx < ft[j])
            {
                mx = ft[j];
                p = heightPar[j];
            }
        }

        dp[i] = mx + 1;
        par[i] = p;
        ft[arr[i].h]=dp[i];
        heightPar[arr[i].h]=i;

        if(MX<dp[i])
        {
            MX=dp[i];
            INDEX=i;
        }
    }

    cout<<MX<<endl;
    vector<int>res;

    while (INDEX>0)
    {
        res.push_back(arr[INDEX].index);
        INDEX=par[INDEX];
    }
    
    RREP(i,res.size()-1,0)
    cout<<res[i]<<" ";
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