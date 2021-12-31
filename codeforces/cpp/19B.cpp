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

struct product
{
	int t;
	ll cost;
} arr[2001];
int N;

ll dp[2001][2001];

ll fun(int pos = 1, int t = 0)
{
	if(t>N)t=N;
	if(pos>N)
	{
		return t==N?0:1e18;
	}
	else if(dp[pos][t]!=-1)
		return dp[pos][t];
	else
	{
		return  dp[pos][t] = min(arr[pos].cost + fun(pos+1,t+arr[pos].t+1), fun(pos+1,t));
	}
}

void solve()
{
	cin >> N;

	REP(i, 1, N)
	cin >> arr[i].t >> arr[i].cost;

	memset(dp,-1,sizeof(dp));

	cout << fun();
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