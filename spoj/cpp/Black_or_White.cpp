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

int n;
int arr[201];
int dp[201][201][201];

int fun(int pos, int black, int white)
{
    if(pos==n+1)
        return 0;
    else if(dp[pos][black][white]!=-1)
        return dp[pos][black][white];
    else
    {
        int v1 = INF;
        int v2 = INF;

        if(arr[pos]>arr[white]||white==0)
            v1=fun(pos+1,black,pos);
        if(arr[pos]<arr[black]||black==0)
            v2=fun(pos+1,pos,white);

        return dp[pos][black][white] = min({v1,v2,1+fun(pos+1,black,white)});
    }
}

void solve()
{
    while (true)
    {
        cin >> n;

        if (n == -1)
            return;

        REP(i, 1, n)
        cin >> arr[i];

        memset(dp,-1,sizeof(dp));
        cout<<fun(1,0,0)<<endl;
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