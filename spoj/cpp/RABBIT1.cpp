#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long int
// #define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll u[2][2], trans[2][2];
ll m;
ll _arr[21];

void init()
{
    _arr[0] = 1;

    for (int i = 0; i < 20; i++)
    {
        _arr[i + 1] = 2 * _arr[i];
    }
}

void matmul(ll a[][2], ll b[][2])
{
    ll _u[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            _u[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                _u[i][j] = ((((a[i][k] % _arr[m]) * (b[k][j] % _arr[m])) % _arr[m]) + _u[i][j]) % _arr[m];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[i][j] = _u[i][j];
        }
    }
}

void binexp(ll pow)
{
    u[0][0] = u[1][1] = 1;
    u[1][0] = u[0][1] = 0;

    trans[0][0] = 0;
    trans[0][1] = trans[1][0] = trans[1][1] = 1;

    while (pow)
    {
        if (pow % 2)
            matmul(trans, u);

        matmul(trans, trans);
        pow /= 2;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
        {
            cout << 2 % _arr[m] << endl;
        }
        else
        {
            binexp(n - 1);
            cout << (u[0][0] + (2 * u[1][0]) % _arr[m]) % _arr[m] << endl;
        }
    }

    return 0;
}