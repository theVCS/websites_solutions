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

ll dp[61][2][61][61];

ll digitDP(int pos, int flag = 1, int oneCnt=0, int zeroCnt=0)
{
    if (pos == 0)
        return oneCnt==zeroCnt && oneCnt;
    else if (dp[pos][flag][oneCnt][zeroCnt] != -1)
        return dp[pos][flag][oneCnt][zeroCnt];
    else
    {
        ll ans = 0;
        
        if(flag)
            ans += digitDP(pos-1,1,oneCnt,zeroCnt);
        else
            ans += digitDP(pos-1,0,oneCnt,zeroCnt+1);
        
        ans += digitDP(pos-1,0,oneCnt+1,zeroCnt);
        return dp[pos][flag][oneCnt][zeroCnt] = ans;
    }
}

int check(ll val)
{
    int c1=0,c2=0;

    RREP(i,63,0)
    {
        if(val & (1LL<<i))c1++;
        else if(c1)c2++;
    }

    return c1==c2;
}

void solve()
{
	ll n;
    cin>>n;
    int N = log2l(n);
    cout<<digitDP(N)+check(n)<<endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int t = 1;

    memset(dp,-1,sizeof(dp));
	cin >> t;
	
    REP(tc, 1, t)
	{
		// cout<<"Case "<<tc<<":"<<endl;
		solve();
	}

	return 0;
}