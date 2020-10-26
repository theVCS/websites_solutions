#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
bool sieve[maxN];
vector<int>primes;

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

    for (int i = 2; i < maxN; i++)
    {
        if (!sieve[i])
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
    cout<<primes[10000];

    return 0;
}