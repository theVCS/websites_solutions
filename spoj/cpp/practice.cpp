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

ll binExp(ll a, ll p, ll m = mod)
{
	ll res = 1;

	while (p)
	{
		if (p & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		p >>= 1;
	}

	return res;
}

string str;
ll dp[19][2][163];

ll digitDP(int pos = 0, int flag = 1, ll res = 0)
{
	if (pos == str.size())
		return res;
	else
	{
		ll ans = 0;
		int ub = flag ? (str[pos] - '0') : 9;

		REP(i, 0, ub)
		{
			ans += digitDP(pos + 1, ((i == ub) & flag), res + i);
		}

		return ans;
	}
}

void solve()
{
	ll l, r;
	cin >> l >> r;
	l--;

	memset(dp, -1, sizeof(dp));
	str = to_string(r);
	ll ans = digitDP();

	memset(dp, -1, sizeof(dp));
	str = to_string(l);
	ans -= digitDP();

	cout << ans << endl;
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