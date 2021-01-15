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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool sieve[maxN];

void init()
{
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!sieve[i])
        {
            for (int j = i * i; j < maxN; j += i)
            {
                sieve[j] = true;
            }
        }
    }
}

bool isPos(ll n)
{
    ll a = sqrt(n);

    // sieve[n] will be false if a is prime and true if a is composite
    if (a * a == n && !sieve[a]) // checking if n is a perfect square and sqrt(n) is a prime number
    {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int n;
    ll a;

    cin >> n;

    while (n--)
    {
        cin >> a;

        if (isPos(a))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }

    return 0;
}