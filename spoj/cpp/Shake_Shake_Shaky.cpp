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

ll n, k;
ll arr[50001];

bool isValid(ll p)
{
    if(p==0)return true;
    ll cnt=0;

    REP(i,1,n)
    {
        cnt+=arr[i]/p;
        if(cnt>=k)return true;        
    }

    return cnt>=k;
}

void solve()
{
	cin>>n>>k;

    REP(i,1,n)
    cin>>arr[i];

    ll start=0,end=1000000000;
    ll ans=0;

    while (start<=end)
    {
        ll mid=(start+end)/2;
        if(isValid(mid))ans=max(ans,mid), start=mid+1;
        else end=mid-1;
    }
    
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