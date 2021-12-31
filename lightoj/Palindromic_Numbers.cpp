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

string str;
int N;
ll dp[19][20][20][20];

ll digitDp(int pos, int left_lo, int left_hi, int zeros=0)
{
    if(pos>(N-1-pos+zeros))
    {
        return left_lo<=left_hi;
    }

    if(dp[pos][left_lo][left_hi][zeros]!=-1)
        return dp[pos][left_lo][left_hi][zeros];

    ll ans = 0;

    REP(i,0,9)
    {
        int nlo = left_lo;
        int nhi = left_hi;

        if(i < (str[pos]-'0') && pos < nlo)nlo=pos;
        if(i < (str[N-1-pos+zeros]-'0') && N-1-pos+zeros<nlo)nlo=N-1-pos+zeros;
        if(i > (str[pos]-'0') && pos < nhi)nhi=pos;
        if(i > (str[N-1-pos+zeros]-'0') && N-1-pos+zeros < nhi)nhi=N-1-pos+zeros;

        ans += digitDp(pos+1,nlo,nhi,zeros + (zeros==pos && i==0));
    }

    return dp[pos][left_lo][left_hi][zeros] = ans;
}

int check(string &s)
{
    int i = 0, j = s.size()-1;

    while (i < j)
    {
        if(s[i]!=s[j])
            return 0;
        i++,j--;
    }

    return 1;
}

void solve()
{
    ll ans = 0;
    cin>>str;
    N = str.size();
    memset(dp,-1,sizeof(dp));
    ans-=digitDp(0,N+1,N+1,0);
    ans+=check(str);
    
    cin>>str;
    N = str.size();
    memset(dp,-1,sizeof(dp));
    ans+=digitDp(0,N+1,N+1,0);
    
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
        cout<<"Case "<<tc<<": ";
        solve();
    }

    return 0;
}