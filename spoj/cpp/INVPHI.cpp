#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 202918036
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int phi[202918036];
int invphi[202918031];

void init()
{
    for (int i = 1; i < maxN; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i < maxN; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }

    for (int i = 1; i < maxN; i++)
    {
        if (invphi[phi[i]] == 0)
        {
            invphi[phi[i]] = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (invphi[n] == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << invphi[n] << endl;
        }
    }

    return 0;
}