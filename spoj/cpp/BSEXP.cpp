#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> primes;

void init(int maxN=1000001)
{
    int arr[maxN]

        for (int i = 2; i * i <= maxN; i++)
    {
        if (arr[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j < maxN; j++)
            {
                arr[j] = 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    cin>>t;
    ll n, cnt = 0, base = 2;

    while (t--)
    {
        cin>>n;
        
        for (int i : primes)
        {
            
        }
        
    }
    

    return 0;
}