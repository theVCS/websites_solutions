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

ll dp[65][10];
ll arr[1001];

ll fun(int pos, int prev=0)
{
    if(pos==0)
        return 1;
    else if(dp[pos][prev]!=-1)
        return dp[pos][prev];
    else
    {
        ll ans = 0;

        REP(i,prev,9)
        {
            ans+=fun(pos-1,i);
        }

        return dp[pos][prev] = ans;
    }
}

void solve()
{
	int p,n;
    cin>>p>>n;
    arr[p]=fun(n);
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

    REP(i,1,t)
        cout<<i<<" "<<arr[i]<<endl;

	return 0;
}