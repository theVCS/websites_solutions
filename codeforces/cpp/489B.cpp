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

int n,m;
int boys[101];
int girls[101];
queue<int>q[101];

void solve()
{
	cin>>n;

    REP(i,1,n)
    cin>>boys[i];

    cin>>m;

    REP(i,1,m)
    cin>>girls[i];

    sort(boys+1,boys+1+n);
    sort(girls+1,girls+1+m);

    int ans = 0;

    REP(i,1,n)
    {
        REP(j,1,m)
        {
            if(abs(boys[i]-girls[j])<=1)
            {
                girls[j]=5000;
                ans++;
                break;
            }                
        }
    }

    cout<<ans;
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