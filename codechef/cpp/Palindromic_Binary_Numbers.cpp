#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
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

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        power >>= 1;
    }
    return res;
}

int n;
vector<int> vec;

bool isSet(int n, int index)
{
    return n & (1 << index);
}

void fun(int n)
{
    // cout<<"now-> "<<n<<endl;
    if (n == 0)
        return;

    if (n % 2 == 0)
    {
        vec.push_back(1);
        fun(n - 1);
    }
    else
    {
        int index = 20;
        while (isSet(n,index) == 0)
            index--;

        int start = index, end = 0;
        int rem = 0;
        int curr = 0;

        // cout<<start<<endl;

        while (start > end)
        {
            if (isSet(n, start) == isSet(n, end))
            {
                curr += isSet(n, start) * (1 << start) + isSet(n, end) * (1 << end);
            }
            else
            {
                rem += isSet(n, start) * (1 << start) + isSet(n, end) * (1 << end);
            }

            start--, end++;
        }

        if(start==end)
            curr += isSet(n,start)*(1<<start);

        if (curr)
            vec.push_back(curr);
        fun(rem);
    }
}

void solve()
{
    vec.clear();
    cin >> n;

    fun(n);

    sort(all(vec));

    // int index = 0;

    // while (vec[index]==1)
    // {
    //     index++;
    // }
    
    // if(index%)

    cout << vec.size() << endl;
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("inputD.txt","r",stdin);
    // freopen("a.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}