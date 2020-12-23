#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool isPrime[maxN];
map<int, int> primes;

void init()
{
    int pos = 1;
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i <= maxN; i++)
    {
        if (!isPrime[i])
        {
            isPrime[i] = pos++;

            for (int j = i * i; j < maxN; j += i)
            {
                isPrime[j] = true;
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

    int t, n, row, col;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (primes[n])
        {
            row = int(ceil((sqrt(8*primes[n] + 1) - 1)/2));
            col = primes[n] - (row * (row - 1)) / 2;
            cout << row << " " << col << endl;
            // cout << primes[n] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}