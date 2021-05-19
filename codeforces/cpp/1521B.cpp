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
#define maxN 120001
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
            for (int j = 2 * i; j < maxN; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    REP(i, 2, maxN - 1)
    if (sieve[i] == false)
    {
        primes.push_back(i);
        // cout<<i<<" ";
    }
    // cout<<endl;
}

ll arr[100001];

void solve()
{
    int n;
    cin >> n;

    arr[0] = 1000000009;

    REP(i, 1, n)
    cin >> arr[i];

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    if (n == 2)
    {
        cout << 1 << endl;
        cout << 1 << " " << 2 << " " << mod << " " << min(arr[1], arr[2]) << endl;
        return;
    }

    cout << n - 1 << endl;

    REP(i, 1, n - 2)
    {
        cout << i << " " << i + 1 << " " << arr[i - 1] + 1 << " " << min(arr[i], arr[i + 1]) << endl;
        arr[i + 1] = min(arr[i], arr[i + 1]);
        arr[i] = arr[i - 1] + 1;
    }

    cout << n - 1 << " " << n << " " << mod << " " << min(arr[n - 1], arr[n]) << endl;
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

    // init();

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