#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
// #define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll remainder(string num, ll m)
{
    vector<int> vec;
    ll mod = 0;

    // Do step by step division
    for (int i = 0; i < num.size(); i++)
    {

        int digit = num[i] - '0';

        mod = mod * 10 + digit;
        int quo = mod / m;
        vec.push_back(quo);
        mod = mod % m;
    }

    return mod;
}

ll binexp(ll a, ll pow, ll mod = 5)
{
    ll res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        pow /= 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;

    ll rem = remainder(s, 4), sum = 0;

    for (int i = 1; i < 5; i++)
    {
        sum += binexp(i, rem);
    }
    sum %= 5;

    cout << sum;

    return 0;
}