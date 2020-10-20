#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    ll n, res = 1, a = 5;
    cin>>n;

    while (n)
    {
        if (n % 2)
        {
            res = (res * a)%100;
            n--;
        }
        n /= 2;
        a = (a * a) % 100;
    }
    cout<<res;

    return 0;
}