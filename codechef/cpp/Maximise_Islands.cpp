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

int n, m;
char arr[11][11];
char conf[11][11];

void init()
{
    conf[1][1] = '*';

    REP(i, 1, 11)
    {
        if (i > 1)
        {
            if (conf[i - 1][1] == '.')
            {
                conf[i][1] = '*';
            }
            else
            {
                conf[i][1] = '.';
            }
        }

        REP(j, 2, 11)
        {
            if (conf[i][j - 1] == '.')
            {
                conf[i][j] = '*';
            }
            else
            {
                conf[i][j] = '.';
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, s1, s2;

    cin >> t;

    while (t--)
    {
        bool flag = false;

        s1 = s2 = 0;

        cin >> n >> m;

        if ((n * m) % 2)
            flag = true;

        REP(i, 1, n + 1)
        {
            REP(j, 1, m + 1)
            {
                cin >> arr[i][j];

                if (arr[i][j] == conf[i][j])
                {
                    s2++;
                }
                else
                {
                    s1++;
                }
            }
        }

        if (flag)
        {
            cout << s1 << endl;
        }
        else
        {
            cout << min(s1, s2) << endl;
        }
    }

    return 0;
}