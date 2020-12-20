#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 90000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool isPrime[maxN];
vector<int> primes;

void init()
{
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j < maxN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    for (int i = 2; i < maxN; i++)
    {
        if (!isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int q, n;

    cin >> q;

    while (q--)
    {
        cin >> n;

        cout << primes[n - 1] << "\n";
    }

    return 0;
}