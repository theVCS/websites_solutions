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
    ll prev, cur, res = -1;

    cin>>n;
    cin>>prev;
    n--;

    while (n--)
    {
        cin>>cur;
        res = max(res, (cur^prev));
        prev = cur;
        cout<<res<<endl;
    }

    // cout<<res;

    return 0;
}