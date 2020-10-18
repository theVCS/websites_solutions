#include <bits/stdc++.h>
using namespace std;
int nMax = 900000;
bool isPrime[900000];


int main()
{
    vector<int> primes;
    isPrime[0] = isPrime[1]  = true;

    for (int i = 2; i * i <= nMax; i++)
    {   
        if (!isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= nMax; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    int q, k;
    cin >> q;

    while (q--)
    {
        cin >> k;
        cout<<primes[k - 1]<<endl;
    }
    
    return 0;
}