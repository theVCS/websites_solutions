#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll nthsum(ll n)
{
    return (n * (n + 1)) / 2;
}

void counter(ll n)
{
    ll rsum, i = 1, cursum, dig;
    ll swap = 0;
    rsum = nthsum(n);

    if (rsum % 2)
    {
        cout<<swap<<endl;
        return;
    }

    rsum /= 2;

    cursum = nthsum(i);
    while (rsum > cursum)
    {
        dig = rsum - cursum + 1;
        if (dig > i && dig <= n)
        {
            swap += n - dig + 1;
        }
        
        i++;
        cursum = nthsum(i);
    }

    if (rsum == cursum)
    {
        swap++;
    }
    
    cout<<swap<<endl;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        counter(n);
    }
    

    return 0;
}