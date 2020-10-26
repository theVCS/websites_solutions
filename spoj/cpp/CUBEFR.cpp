#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
int sieve[maxN];
map<int, int> cfn;

void init()
{
    int count = 1;

    for (int i = 2; i < maxN; i++)
    {
        sieve[i] = i;
    }

    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i; j < maxN; j += i)
            {
                if (sieve[j] == j)
                {
                    sieve[j] /= i;
                }
            }
        }
    }

    cfn[1] = 1;
    for (int i = 2; i < maxN; i++)
    {
        int n = i;
        map<int, int> factors;
        while (sieve[n])
        {
            if (factors.find(n) == factors.end())
            {
                factors[(n / sieve[n])] = 1;
            }
            else
            {
                factors[(n / sieve[n])] += 1;
            }

            n = sieve[n];
        }

        for (auto P : factors)
        {
            if (P.second > 2)
            {
                cfn[i] = 0;
                break;
            }
        }

        if (cfn.find(i) != cfn.end())
        {
            count++;
            cfn[i] = count;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    for(auto P: cfn)
    {
        cout<<P.first<<" "<<P.second<<endl;
    }
    // cout << cfn[8];

    return 0;
}