#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll n, l, r, k;
ll arr[maxN];

int fun(int n, ll k)
{
    if(n==0||k==0)return 0;
    else if(arr[n]<=k)
    {
        return max(1+fun(n-1,k-arr[n]), fun(n-1, k));
    }
    else
        return fun(n-1,k);
}

void solve()
{
    int index = 1;
	cin>>n>>l>>r>>k;

    REP(i,1,n)
    {
        ll v;
        cin>>v;

        if(v>=l && v <= r)
            arr[index++]=v;
    }

    int n = index - 1;
    sort(arr+1,arr+1+n);

    ll s = 0;
    index = 1;
    
    while (s<=k && index <= n)
    {
        s += arr[index];
        index++;
    }

    if(s>k)index--;

    cout<<index-1<<endl;
    
    // cout<<fun(n,k)<<endl;
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