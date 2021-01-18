#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int,int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
    
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    ll dum;
    int prod = 1;
    ll res = 0;
    bool zeroCount = false;

    cin >> n;

    while (n--)
    {
        cin >> dum;

        if(dum == 0)
        {
            zeroCount = true;
            res++;
        }
        else if (dum > 0)
        {
            res += dum - 1;
        }
        else
        {
            res += abs(dum) - 1;
            prod *= -1;
        }
    }

    if (prod == -1)
    {
        if(zeroCount)
        {
            cout << res;
        }
        else
        {
            cout << res + 2;
        }
    }
    else
    {
        cout << res;
    }
    
    
    return 0;
}