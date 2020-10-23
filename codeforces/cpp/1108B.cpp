#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<ll> arr1;
    vector<ll> arr2;
    ll dig1 = 1, dig2 = 1, dum;
    cin>>n;

    while (n--)
    {
        cin>>dum;

        if(count(arr1.begin(), arr1.end(), dum))
        {
            arr2.push_back(dum);
            dig2 = (dig2 * dum)/__gcd(dig2, dum);
        }
        else
        {
            arr1.push_back(dum);
            dig1 = (dig1 * dum)/__gcd(dig1, dum);
        }
    }
    
    cout<<dig1<<" "<<dig2;

    return 0;
}