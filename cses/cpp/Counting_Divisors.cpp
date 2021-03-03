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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sieve[maxN];
vector<pii> numDiv[maxN]; // stores the factorization of number
int maxPower[maxN];       // stores the maximum power of a factor

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j < maxN; j += i)
            {
                if (sieve[j] == 0)
                    sieve[j] = i;
            }
        }
    }
}

void divisors(int n)
{
    map<int, int> count;

    while (sieve[n])
    {
        count[sieve[n]]++;
        n = n / sieve[n];
    }

    int res = 1;

    for (auto e : count)
    {
        maxPower[e.first] = max(maxPower[e.first], e.second);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << divCount(n) << endl;
    }

    return 0;
}