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

int n;
int str[100];

bool fun(int pos=1, int sum1=0, int sum2=0)
{
	if(pos==100)
		return sum1==sum2 && sum1;
	else if(str[pos]==0)
		return fun(pos+1,sum1,sum2);
	else
		return fun(pos+1,sum1,sum2)||fun(pos+1,sum1+pos,sum2)||fun(pos+1,sum1,sum2+pos);
}

void solve()
{
	int ans=0;
	memset(str,0,sizeof(str));

	cin>>n;

	REP(i,1,n)
	{
		int temp;
		cin>>temp;
		ans|=str[temp];
		str[temp]=1;
	}

	if(ans)
	{
		cout<<"YES"<<endl;
		return;
	}

	if(fun())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
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