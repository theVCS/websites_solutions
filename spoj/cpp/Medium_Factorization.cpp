#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100011
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sieve[maxN];

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j < maxN; j += i)
            {
                if (sieve[j] == 0)
                {
                    sieve[j] = i;
                }
            }
        }
    }
}

void div(int n)
{
    printf("1");
    while (sieve[n])
    {
        printf(" x ");
        printf("%d", sieve[n]);
        n = n / sieve[n];
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    init();

    int n;

    while (scanf("%d", &n) != EOF)
    {
        div(n);
    }

    return 0;
}