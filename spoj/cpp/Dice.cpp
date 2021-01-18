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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

float t[3010][3010];

void init()
{
    t[0][0] = 1.0;

    for (int i = 1; i < 3001; i++)
    {
        for (int j = 1; j < 3001; j++)
        {
            t[i][j] = 0;

            for (int k = 1; k <= 6; k++)
            {
                if (j >= k)
                {
                    t[i][j] += t[i - 1][j - k];
                }
            }
            t[i][j] *= 1.0 / 6;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int cs, n, k;

    cin >> cs;

    while (cs--)
    {
        cin >> n >> k;

        if (n > 3000 || k > 3000)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << int(t[n][k] * 100) << endl;
        }
    }

    return 0;
}