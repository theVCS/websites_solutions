#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool isPrime[maxN];
vector<int> prime;

void init()
{
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i * i <= maxN; i++)
    {
        for (int j = i * i; j < maxN; j += i)
        {
            isPrime[j] = true;
        }
    }

    REP(i, 2, maxN)
    {
        if (isPrime[i] == false)
            prime.push_back(i);
    }
}

void solve()
{
    int d;
    cin >> d;

    ll res = 1;

    int p1 = lower_bound(all(prime), d + 1) - prime.begin();
    p1 = prime[p1];

    res *= p1;

    p1 = lower_bound(all(prime), d + p1) - prime.begin();
    p1 = prime[p1];

    res *= p1;

    cout << res << endl;
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