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
#define maxN 10000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sieve[maxN];

void init()
{
    for(int i = 2; i * i <= maxN; i++)
    {
        if (sieve[i] == 0)
        {
            sieve[i] = i;

            for (int j = i * i; j < maxN; j += i)
            {
                if (sieve[j] == 0)
                    sieve[j] = i;
            }
        }
    }
}

ll sum(int n)
{
    map<int, ll> mp;

    while (sieve[n])
    {
        if (mp[sieve[n]] == 0)
            mp[sieve[n]] = 1;
        mp[sieve[n]] *= sieve[n];
        n /= sieve[n];
    }

    ll res = 1;

    for (auto div : mp)
    {
        res *= ((div.second * div.first - 1) / (div.first - 1));
        if (res > 10000000)
            return 0;
    }

    return res;
}

int res[10000001];

void preprocess()
{
    init();

    REP(i, 1, maxN - 1)
    {
        ll divSum = sum(i);

        if (res[divSum] == 0)
            res[divSum] = i;
    }
}

void solve()
{
    int n;
    cin >> n;

    if (res[n] == 0)
        cout << -1 << endl;
    else
        cout << res[n] << endl;

    // cout<<sum(66949)<<endl;
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

    preprocess();

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