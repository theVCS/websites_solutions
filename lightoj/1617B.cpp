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

ll div(ll n)
{
    int index = 1;

    while(n % 2 == 0)
    {
        n /= 2;
        index *= 2;
    }

    if(index>1)return index;

    for (ll i = 3; i*i <= n; i+=2)
    {
        if(n % i == 0)
            return i;
    }
    

    return 1;
}

void solve()
{
    ll n;   
    cin>>n;
    n-=1;

    if(n & 1)
    {
        ll a = n/2;
        ll b = a+1;
        cout<<a<<" "<<b<<" "<<1<<endl;
    }
    else
    {
        ll m = n/2;

        if(m & 1)
        {
            cout<<m-2<<" "<<m+2<<" "<<1<<endl;   
        }
        else
        {
            cout<<m-1<<" "<<m+1<<" "<<1<<endl;   
        }
    }
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