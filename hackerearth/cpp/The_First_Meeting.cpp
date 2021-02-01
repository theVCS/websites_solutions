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

bool isPrime[maxN];

void init()
{
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j < maxN; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    init();

    int n, ai, maxPrime = INT_MIN, minPrime = INT_MAX;

    scanf("%d", &n);

    REP(i, 0, n)
    {
        scanf("%d", &ai);

        if (!isPrime[ai])
        {
            maxPrime = max(maxPrime, ai);
            minPrime = min(minPrime, ai);
        }
    }

    if (maxPrime == INT_MIN || minPrime == INT_MAX)
    {
        printf("1");
    }
    else
    {
        printf("%d", abs(maxPrime - minPrime));
    }

    return 0;
}