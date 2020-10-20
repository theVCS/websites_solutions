#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000001
#define REP(i, a, b) for (int i = a; i < b; i++)

ll phi[max];

void init(ll n=max)
{
    for (ll i = 1; i < n; i++)
    {
        phi[i] = i;
    }

    for (ll i = 2; i < n; i++)
    {
        if (phi[i] == i)
        {
            for (ll j = i; j < n; j += i)
            {
                phi[j] *= i - 1;
                phi[j] /= i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    init();
    ll t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<phi[n]<<endl;
    }
    

    return 0;
}