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

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2LL) % c;
        b /= 2;
    }

    return x % c;
}

ll binExp(ll a, ll p, ll m = mod)
{
    ll res = 1;
    a %= m;

    while (p)
    {
        if (p & 1)
            res = mulmod(res,a,m);
        a = (a * a) % m;
        p >>= 1;
    }

    return res;
}

bool isComposite(ll a, ll d, ll s, ll n)
{
    ll res = binExp(a, d, n);
    if (res == 1 || res == n - 1)return false;

    for (ll i = 1; i < s; i++)
    {
        res = mulmod(res,res,n);
        if (res == n - 1)return false;
    }
    
    return true;
}
 
bool isPrime(ll n)
{
    if (n <= 4)return (n == 2 || n == 3);
    if(n % 2 == 0)return false;
 
    ll d = n - 1, s = 0;
 
    while (d % 2 == 0)
        d /= 2,s++;
 
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)return true;
        if (isComposite(a, d, s, n))return false;
    }

    return true;
}

string s;
ll res;

void fun(int pos=0, int flag=1, ll dig=0)
{
    if(pos==s.size())
    {
        // cout<<dig<<endl;
        if(isPrime(dig))
        {
            res=dig;
        }
    }
    else
    {
        for (int i : {7,5,3,2})
        {
            if((s[pos]-'0')<i && flag)
                continue;
            
            fun(pos+1,flag & ((s[pos]-'0')==i),dig*10+i);
            
            if(res!=-1)
                return;
        }
    }
}

void solve()
{
	res=-1;
    cin>>s;
    REP(i,0,s.size()-1)
    {
        fun(i,i==0);
        
        if(res!=-1)
        {
            cout<<res<<endl;
            return;
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
		cout<<"Case "<<tc<<": ";
		solve();
	}

	return 0;
}