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

ll k;
ll cnt[13];

ll numberFormer(ll dig)
{
    ll d = 1;

    dig--;

    while (dig--)
        d *= 10;

    return d;
}

void solve()
{
    cin >> k;

    cnt[1] = 9;

    ll n = 9;
    ll dig = 1;

    REP(i, 1, 12)
    {
        cnt[i] = cnt[i - 1] + n * dig;
        n *= 10;

        if (cnt[i] >= k)
        {
            break;
        }

        dig++;
    }

    // cout << dig;
    ll startIndex = cnt[dig - 1] + 1;
    ll dis = (k - startIndex + dig) / dig;

    ll number = numberFormer(dig) + (dis - 1);
    startIndex += (dis - 1) * dig;
    ll index = startIndex;
    string num = to_string(number);

    while (true)
    {
        if(index == k)
        {
            cout<<num[index-startIndex];
            return;
        }

        index++;
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}