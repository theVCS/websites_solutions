#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;
ll powerRaised[10];

ll fun(int n = 0, int rem = 0, int target = 1, int div = 1)
{
    if(n == s.size())
    {
        return rem == 0;
    }
    else if (target)
    {   
        ll res = 0;

        REP(i,1,s[n]-'0')
        {
            int d = div * gcd(div,i);
            res+=fun(n+1,(rem*10+i)%d,)
        }
    }
    else
    {
        
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    powerRaised[1] = 1;
    powerRaised[2] = 4;
    powerRaised[3] = 27;
    powerRaised[4] = 256;
    powerRaised[5] = 3125;
    powerRaised[6] = 46656;
    powerRaised[7] = 823543;
    powerRaised[8] = 16777216;
    powerRaised[9] = 387420489;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}