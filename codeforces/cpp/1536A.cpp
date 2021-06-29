#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n;
map<ll, int> mp;
vector<ll> vec;

void fun()
{
    REP(i, 0, n - 1)
    {
        REP(j, i + 1, n - 1)
        {
            ll ele = abs(vec[i] - vec[j]);

            if (mp[ele] == 0)
            {
                vec.push_back(ele);
                mp[ele] = 1;
            }
        }
    }
}

void solve()
{
    mp.clear();
    vec.clear();

    ll dum;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> dum;
        mp[dum] = 1;
        vec.push_back(dum);
    }

    while (true)
    {
        fun();

        if(n == vec.size())
        {
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for(ll ele: vec)cout<<ele<<" ";
            cout<<endl;
            return;
        }
        else
        {
            if(vec.size() > 300)
            {
                cout<<"NO"<<endl;
                return;
            }   
            else
            {
                n = vec.size();
                fun();
            }
            
        }
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}