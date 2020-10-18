#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int max = 10001;
bool isPrime[10001];

void sieve()
{
    isPrime[0] = isPrime[1] = true;

    for (int i = 0; i * i <= 10001; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j < 10001; j += i)
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

    sieve();
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        if (!isPrime[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}