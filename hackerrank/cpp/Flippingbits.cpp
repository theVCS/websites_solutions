#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unsigned int t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<(4294967295 ^ n)<<endl;
    }


    return 0;
}