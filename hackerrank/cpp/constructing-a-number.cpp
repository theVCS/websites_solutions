#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll digitSum(ll a)
{
    ll sum = 0;

    while (a)
    {
        sum += a % 10;
        a /= 10;
    }

    return sum % 3;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    ll d, sum;

    cin>>t;

    while (t--)
    {
        sum = 0;
        cin>>n;

        REP(i, 0, n)
        {
            cin>>d;
            sum = (sum + digitSum(d)) % 3;
        }

        if (!sum)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        
    }
    

    return 0;
}