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

string s,t;
int k;
int dp[1001][1001];

int fun(int i, int j)
{
    if(i<=0||j<=0)
        return 0;
    else if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        int ans = 0;
        int c = 1;

        while (i-c>=0 && j-c>=0 && s[i-c] == t[j-c])
        {
            if(c>=k)
                ans=max(ans,c+fun(i-c,j-c));
            c++;
        }

        return dp[i][j] = max({ans,fun(i-1,j),fun(i,j-1)});
    }
}

void solve()
{
    while (true)
    {
        cin>>k;
        if(k==0)return;
        cin>>s>>t;

        REP(i,1,s.size())
        REP(j,1,t.size())
        dp[i][j]=-1;
        
        cout<<fun(s.size(),t.size())<<endl;
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