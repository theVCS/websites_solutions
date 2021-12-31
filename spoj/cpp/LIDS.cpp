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

string str1;
string str2;
ll dp[11][11][11][2];
int N;

ll digitDP(int pos, int len, int flag1 = 1, int flag2 = 1, int lastDigit = -1, int nonZero = 0)
{
	if (pos == -1)
		return len == 0;

	ll &res = dp[pos][len][lastDigit+1][nonZero];

	if (flag1 == 0 && flag2 == 0 && res != -1)
		return res;

	ll ans = 0;

	int lb = flag1 ? (str1[pos] - '0') : 0;
	int ub = flag2 ? (str2[pos] - '0') : 9;

	REP(i, lb, ub)
	{
		ans += digitDP(pos-1,len,flag1 & (i==lb), flag2 & (i==ub), lastDigit, nonZero||i);

		if(len && lastDigit < i && (nonZero || i))
		{
			ans += digitDP(pos-1,len-1,flag1 & (i==lb), flag2 & (i==ub), i, 1);
		}
	}

	return flag1 == 0 && flag2 == 0 ? res = ans : ans;
}

void solve()
{
	cin >> str1 >> str2;

	reverse(all(str1));
	reverse(all(str2));

	while (str1.size() < str2.size())
	{
		str1.push_back('0');
	}

	N = str1.size();

	RREP(i,10,1)
	{
		ll ans = digitDP(N - 1, i);
		// cout<<ans<<endl;
		if(ans)
		{
			cout<<i<<" "<<ans<<endl;
			return;
		}
	}

	cout<<0<<" "<<1<<endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	memset(dp, -1, sizeof(dp));

	int t = 1;
	cin >> t;

	REP(tc, 1, t)
	{
		cout << "Case " << tc << ": ";
		solve();
	}

	return 0;
}