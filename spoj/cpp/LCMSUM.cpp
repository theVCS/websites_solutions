#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sieve[maxN];
ll ans[maxN];

void init()
{
    for (int i = 1; i < maxN; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i; j < maxN; j += i)
            {
                sieve[j] /= i;
                sieve[j] *= i - 1;
            }
        }
    }

    for (int i = 1; i < maxN; i++)
    {
        for (int j = i; j < maxN; j += i)
        {
            ans[j] += i * sieve[i];
        }
    }
}

ll lcmSum(int n)
{
    return ((ans[n] + 1) * n) / 2;
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
        cout << lcmSum(n) << endl;
    }

    return 0;
}