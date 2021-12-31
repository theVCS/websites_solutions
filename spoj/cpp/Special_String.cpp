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

int check(int p1, int p2, int curr)
{
    return p1!=p2 && p1!=curr && p2!=curr && p1 && p2;
}

ll dp[31][4][4][2];

ll fun(int pos, int p1=0, int p2=0, int flag=0)
{
    if(pos==0)
        return flag^1;
    else if(dp[pos][p1][p2][flag]!=-1)
        return dp[pos][p1][p2][flag];
    else
    {
        ll ans = 0;

        REP(curr,1,3)
        ans+=fun(pos-1,p2,curr,flag|check(p1,p2,curr));

        return dp[pos][p1][p2][flag] = ans;
    }
}

void solve()
{
	int n;
    cin>>n;
    cout<<fun(n)<<endl;
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