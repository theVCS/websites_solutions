#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 2677
#define REP(i, a, b) for (int i = a; i < b; i++)
short int primes[2677];
vector <short int> ln;

int sieve()
{
    primes[0] = primes[1] = -1;

    for (short int i = 2; i < mod; i++)
    {
        if (primes[i] == 0)
        {
            for (short int j = i; j < mod; j += i)
            {
                primes[j] += 1;
            }
        }
    }

    for (short int i = 2; i < mod; i++)
    {
        if (primes[i] > 2)
        {
            ln.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    sieve();

    short int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << ln[n - 1] << endl;
    }

    return 0;
}