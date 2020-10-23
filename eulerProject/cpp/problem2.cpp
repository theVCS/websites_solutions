#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll sum = 0;
    ll a = 1, b = 1, temp;
    
    while (b <= 4000000)
    {
        temp = b;
        if (b % 2 == 0)
        {
            sum += b;
        }
        b = a + b;
        a = temp;
    }
    
    cout<<sum;
    return 0;
}