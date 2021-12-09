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

void solve()
{
	string s, w;
    cin>>s>>w;

    int pos[26] = {0};

    REP(i,0,25)
        pos[s[i]-'a']=i;

    int ans = 0;

    REP(i,1,w.size()-1)
        ans += abs(pos[w[i]-'a'] - pos[w[i-1]-'a']);

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