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

int sz = 2001;
int dp[2][sz];

int lcsLengthMemoryEfficient(vector<int>&a, vector<int>&b)
{
    int n = a.size();
    int m = b.size();

    REP(i, 0, m)
    dp[0][i] = dp[1][i] = 0;

    REP(i, 1, n)
    REP(j, 1, m)
    {
        int p = (i & 1);

        if (a[i - 1] == b[j - 1])
            dp[p][j] = 1 + dp[p ^ 1][j - 1];
        else
            dp[p][j] = max(dp[p ^ 1][j], dp[p][j - 1]);
    }

    return dp[n & 1][m];
}

void solve()
{
    vector<int>A;
    int ans = 0;

    while(true)
    {
        int a;
        cin>>a;
        if(a==0)break;
        A.push_back(a);
    }

    while (true)
    {
        int x;
        cin>>x;
        if(x==0)break;
        vector<int>B;
        B.push_back(x);

        while(true)
        {
            cin>>x;
            if(x==0)break;
            B.push_back(x);
        }

        ans=max(ans,lcsLengthMemoryEfficient(A,B));
    }
    
    cout<<ans<<endl;
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