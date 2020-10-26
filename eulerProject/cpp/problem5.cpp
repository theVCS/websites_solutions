#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int prod = 1;

    for (int i = 1; i < 21; i++)
    {
        prod *= i / __gcd(i, prod);
    }
    
    cout<<prod;
    
    return 0;
}