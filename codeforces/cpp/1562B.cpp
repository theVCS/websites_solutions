#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
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
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

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

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = mulmod(res,a,m);
        a = mulmod(a,a,m);
        power >>= 1;
    }
    return res;
}

bool isPrime(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if(num%i==0)return false;
    }

    return true;
    
}

void solve()
{
    int n;
    string s;
    cin>>n>>s;

    int fre[10]={0};

    for(char c: s)
    {
        fre[c-'0']++;
    }

    vector<int>vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(9);

    // 0 1 2 3 4 5 6 7 8 9
    for(int num: vec)
    {
        if(fre[num])
        {
            cout<<1<<endl;
            cout<<num<<endl;
            return;
        }
    }

    cout<<2<<endl;

    REP(i,0,n-1)
    {
        REP(j,i+1,n-1)
        {
            int num = (s[i]-'0')*10+(s[j]-'0');

            if(isPrime(num)==false)
            {
                cout<<num<<endl;
                return;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("inputD.txt","r",stdin);
    //freopen("a.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc,1,t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}