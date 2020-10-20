#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll a, b, fac[13];
    fac[0] = fac[1] = 1;

    for (int i = 2; i < 13; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
    cin>>a>>b;
    cout<<fac[min(a, b)];


    return 0;
}