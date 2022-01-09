#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 100001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll n, a, r, m;
ll arr[maxN];

ll f(ll k)
{
    ll c1=0,s1=0,c2=0,s2=0;

    REP(i,1,n)
    {
        if(arr[i]>=k)
        {
            s1+=arr[i];
            c1++;
        }
        else
        {
            s2+=arr[i];
            c2++;
        }
    }

    ll b1=s1-c1*k;
    ll b2=c2*k-s2;

    ll mn = min(b1,b2);
    
    b1-=mn;
    b2-=mn;

    ll cost=mn*min(a+r,m);

    cost+=b1*r;
    cost+=b2*a;

    return cost;
}

void solve()
{
	cin>>n>>a>>r>>m;

    REP(i,1,n)
    cin>>arr[i];

    ll l=0,r=1e9;
    ll ans=1e18;

    while (l<=r)
    {
        ll m1=l+(r-l)/3;
        ll m2=r-(r-l)/3;

        ll c1=f(m1);
        ll c2=f(m2);

        ans=min(ans,c1);
        ans=min(ans,c2);

        if(c1<c2)r=m2-1;
        else if(c1>c2)l=m1+1;
        else l=m1+1,r=m2-1;
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

	// cin >> t;

	REP(tc, 1, t)
	{
		// cout<<"Case "<<tc<<":"<<endl;
		solve();
	}

	return 0;
}