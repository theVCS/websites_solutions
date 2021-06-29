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
#define maxN 40001
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

bool sieve[maxN];
vector<int> primes;

void init()
{
    for (int i = 2; i * i <= maxN; i++)
    {
        if (sieve[i] == false)
        {
            for (int j = i * i; j < maxN; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    REP(i, 2, maxN - 1)
    if (sieve[i] == false)
        primes.push_back(i);
}

void solve()
{
    ll a, b, k;

    cin >> a >> b >> k;

    if (k == 1)
    {
        ll gcd = __gcd(a, b);

        if ((a == gcd && b != gcd) || (b == gcd && a != gcd))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        return;
    }

    ll s1 = 0, s2 = 0;

    for(int p: primes)
    {
        while (a % p == 0)
        {
            a /= p;
            s1++;
        }
    }

    if (a > 1)
        s1++;

    for(int p: primes)
    {
        while (b % p == 0)
        {
            b /= p;
            s2++;
        }
    }

    if (b > 1)
        s2++;

    if (k <= s1 + s2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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

    init();

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