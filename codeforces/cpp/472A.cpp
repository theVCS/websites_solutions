#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (sieve[i] && sieve[n - i])
        {
            cout << i << " " << n - i;
            break;
        }
    }

    return 0;
}