#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10000001
ll sieve[maxN];
ll a[maxN];

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == i)
        {            
            for (int j = 2 * i; j < maxN; j += i)
            {
                if (sieve[j] == j)
                {
                    sieve[j] = i;
                }
            }
        }
    }

    a[0] = a[1] = 0;

    for (int i = 2; i < maxN; i++)
    {
        a[i] = a[i - 1] + sieve[i];
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t;
    ll n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<a[n]<<endl;
    }
    

    return 0;
}