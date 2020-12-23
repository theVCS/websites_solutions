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

bool isPrime[maxN];
int arr[maxN];

bool haveZero(int n)
{
    while (n)
    {
        if (n % 10 == 0)
        {
            return true;
        }
        n /= 10;
    }

    return false;
}

bool allTrunPrime(int n)
{
    int div = 10;

    while (n != n % div)
    {
        if (isPrime[n % div])
        {
            return false;
        }

        div *= 10;
    }

    return true;
}

void init()
{
    // sieve run
    isPrime[0] = isPrime[1] = true;

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
        if (!isPrime[i] && !haveZero(i) && allTrunPrime(i))
        {
            arr[i] = arr[i - 1] + 1;
        }
        else
        {
            arr[i] = arr[i - 1];
        }
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
        cout << arr[n] << endl;
    }

    return 0;
}