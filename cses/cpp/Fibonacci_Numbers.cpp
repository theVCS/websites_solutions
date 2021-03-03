#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll identity[2][2];
ll transition[2][2];

void multiply(ll a[][2], ll b[][2])
{
    ll _u[2][2];

    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            _u[i][j] = 0;

            REP(k, 0, 2)
            {
                _u[i][j] = (_u[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }

    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            b[i][j] = _u[i][j];
        }
    }
}

ll binExp(ll n)
{
    identity[0][0] = identity[1][1] = 1;
    identity[0][1] = identity[1][0] = 0;
    transition[1][0] = transition[0][1] = transition[1][1] = 1;
    transition[0][0] = 0;

    while (n)
    {
        if (n & 1)
            multiply(transition, identity);
        multiply(transition, transition);
        n >>= 1;
    }

    return identity[1][0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    cout << binExp(n);

    return 0;
}