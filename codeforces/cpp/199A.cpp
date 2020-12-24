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

ll u[2][2], a[2][2];

ll findIndex(ll n)
{
    double fibo = 2.078087 * log(n) + 1.672276;
    return round(fibo);
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
                _u[i][j] += a[i][k] * b[k][j];
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

void binexp(int pow)
{
    u[0][0] = u[1][1] = 1;
    a[0][1] = a[1][0] = a[1][1] = 1;

    while (pow)
    {
        if (pow % 2)
        {
            matmul(a, u);
            pow--;
        }
        pow /= 2;
        matmul(a, a);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;

    cin >> n;

    if (n == 1)
    {
        cout << 1 << " " << 0 << " " << 0;
    }
    else if (n == 0)
    {
        cout << 0 << " " << 0 << " " << 0;
    }
    else
    {
        binexp(findIndex(n) - 3);
        cout << u[1][1] << " " << u[1][1] << " " << u[1][0];
    }

    return 0;
}