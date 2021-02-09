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
int sieve[maxN];
vector<int> arr[7];

void init()
{
    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i] == false)
        {
            for (int j = i * i; j < maxN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    for (int i = 2; i < maxN; i++)
    {
        sieve[i] = sieve[i - 1] + int(!isPrime[i]);
    }
}

int main(int argc, char const *argv[])
{
    init();

    int t, x, y;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &x, &y);

        if (sieve[x] > y)
        {
            printf("Divyam\n");
        }
        else
        {
            printf("Chef\n");
        }
    }

    return 0;
}