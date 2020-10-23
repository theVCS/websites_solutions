#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void z(ll n)
{
    ll p = 1;
    ll count = 0;
    ll dum = 1;
    while (dum)
    {
        dum = n/pow(5, p);
        count += dum;
        p++;
    }
    cout<<count<<endl;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        z(n);
    }
    

    return 0;
}