#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i, a, b) for (int i = a; i < b; i++)
ll transition_matrix[2][2];
ll identity_matrix[2][2];

void multiply(ll matrix_a[][2], ll matrix_b[][2])
{
    ll result[2][2];
    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            result[i][j] = 0;
            REP(k, 0, 2)
            {
                result[i][j] += (matrix_a[i][k] % 1000000007) * (matrix_b[k][j] % 1000000007);
            }
        }
    }

    REP(i, 0, 2)
    {
        REP(j, 0, 2)
        {
            matrix_b[i][j] = result[i][j] % 1000000007;
        }
    }
}

void matrixPower(ll power)
{
    transition_matrix[0][0] = 0;
    transition_matrix[0][1] = transition_matrix[1][0] = transition_matrix[1][1] = 1;

    identity_matrix[0][0] = identity_matrix[1][1] = 1;
    identity_matrix[0][1] = identity_matrix[1][0] = 0;

    while (power)
    {
        if (power % 2)
        {
            power--;
            multiply(transition_matrix, identity_matrix);
        }
        power /= 2;
        multiply(transition_matrix, transition_matrix);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    ll a, b, n;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> n;
        matrixPower(n - 1);
        cout << ((a * identity_matrix[0][1]) % 1000000007 + (b * identity_matrix[1][1]) % 1000000007) % 1000000007 << endl;
    }

    return 0;
}