#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Max 1000000
bool isPrime[1000001];
int pp[1000001];

void sieve()
{
    int cnt = 0, i, j, total_pp = 0;
    isPrime[0] = isPrime[1] = true;

    for (i = 2; i * i <= Max; i++)
    {
        if (!isPrime[i])
        {
            for (j = i * i; j <= Max; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    for (i = 2; i <= Max; i++)
    {
        if (!isPrime[i])
        {
            cnt++;
        }

        if (!isPrime[cnt])
        {
            total_pp++;
            pp[i] = total_pp;
        }
        else
        {
            pp[i] = total_pp;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    // int t, l, r;
    // cin >> t;

    // while (t--)
    // {
    //     cin >> l >> r;
    //     cout << pp[r] - pp[l] << endl;
    // }
    for (int i = 0; i < Max; i++)
    {
        cout<<i <<" "<<pp[i]<<endl;
    }
    

    return 0;
}