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
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        power >>= 1;
    }
    return res;
}

int n;
int points[3001][2];
int check[3001];

pair<int, int> getReducedForm(int dy, int dx)
{
    int g = __gcd(abs(dy), abs(dx));

    bool sign = (dy < 0) ^ (dx < 0);

    if (sign)
        return make_pair(-abs(dy) / g, abs(dx) / g);
    else
        return make_pair(abs(dy) / g, abs(dx) / g);
}

void minLinesToCoverPoints(int xO, int yO, int i)
{
    map<pair<int, int>, vector<int>> mp;
    pair<int, int> temp;
    int mx = 0;
    pair<int, int> dum;

    for (; i < n; i++)
    {
        if (check[i] == true)
            continue;

        int curX = points[i][0];
        int curY = points[i][1];

        temp = getReducedForm(curY - yO, curX - xO);
        mp[temp].push_back(i);
        
        if(mx < mp[temp].size())
        {
            mx = mp[temp].size();
            dum = temp;
        }
    }

    check[i-1]=true;

    for(int ele: mp[dum])
    {
        // cout<<ele<<" ";
        check[ele] = true;
    }
    // cout<<endl;
}

void solve()
{
    cin >> n;
    REP(i, 0, n - 1)
    cin >> points[i][0] >> points[i][1];

    int res = 0;

    REP(i,0,n-1)
    {
        if(check[i])continue;
        minLinesToCoverPoints(points[i][0], points[i][1], i+1);
        res++;
    }

    cout<<res;
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

    //cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}