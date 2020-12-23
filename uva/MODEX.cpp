#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
    
ll binexp(ll x, ll y, ll n)
{
    ll res = 1;
    x = x % n;

    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % n;
            y--;
        }
        x = (x * x) % n;
        y /= 2;
    }
    return res;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, x, y, n;
    
    cin >> t;

    while (t--)
    {
        cin >> x >> y >> n;
        cout << binexp(x, y, n) << endl;
    }
    
    cin >> t;

    return 0;
}