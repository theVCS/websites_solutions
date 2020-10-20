#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void sub(ll a, ll b)
{
    ll temp;
    int count = 0;
    while (b)
    {
        count += a / b;
        temp = a;
        a = b;
        b = temp % b;
    }
    cout << count << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n, a, b;
    cin>>n;

    while (n--)
    {
        cin>>a>>b;
        sub(a, b);
    }
    

    return 0;
}