#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 2700
#define REP(i, a, b) for (int i = a; i < b; i++)
int primes[mod];
int ln[1000];

bool getCount(int n)
{
    set<int> primefac;
    while (primes[n] != -1)
    {
        primefac.insert(n / primes[n]);
        n = primes[n];
    }

    if (primefac.size() >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sieve()
{
    int count = 0;
    primes[0] = primes[1] = -1;

    for (int i = 2; i < mod; i++)
    {
        if (primes[i] == 0)
        {
            for (int j = i; j < mod; j += i)
            {
                if (primes[j] == 0)
                {
                    primes[j] = j / i;
                }
            }
        }
    }

    for (int i = 30; i < mod; i++)
    {
        if (getCount(i))
        {
            ln[count] = i;
            count++;
        }
    }
}

void display(int n)
{
    set<int> primefac;
    while (primes[n] != -1)
    {
        primefac.insert(n / primes[n]);
        n = primes[n];
    }
    set<int>::iterator iter = primefac.begin();

    while (iter != primefac.end())
    {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    sieve();

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout<<ln[n-1]<<endl;
    }

    return 0;
}