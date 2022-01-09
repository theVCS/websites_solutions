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
	int n;
    string s;
    cin>>n>>s;

    int cnt[51][2];

    memset(cnt,0,sizeof(cnt));

    REP(i,1,n)
    {
        cnt[i][s[i-1]-'a']++;
        cnt[i][0]+=cnt[i-1][0];
        cnt[i][1]+=cnt[i-1][1];
    }

    REP(i,1,n)
    REP(j,i+1,n)
    {
        if(cnt[j][0]-cnt[i-1][0]==cnt[j][1]-cnt[i-1][1])
        {
            cout<<i<<" "<<j<<endl;
            return;
        }
    }

    cout<<-1<<" "<<-1<<endl;
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