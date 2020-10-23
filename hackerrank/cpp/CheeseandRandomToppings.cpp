#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll binexp(ll n ,ll power, ll m)
{
    ll res = 1;

    while (power)
    {
        if (power % 2)
        {
            power--;
            res = (res * n) % m;
        }
        power /= 2;
        n = (n * n) % m;
    }    
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    

    return 0;
}