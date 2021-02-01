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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, ecnt, ocnt;
    ll dum;

    cin >> t;

    while (t--)
    {
        cin >> n;

        ecnt = ocnt = 0;

        REP(i, 0, n)
        {
            cin >> dum;

            if (dum % 2)
            {
                ocnt++;
            }
            else
            {
                ecnt++;
            }
        }

        int turn = 1, win = 1;

        REP(i, 0, n)
        {
            if (turn == 1)
            {
                if (win == 1)
                {
                    // sum is even
                    if (ecnt)
                    {
                        ecnt--;
                    }
                    else
                    {
                        win = 2;
                        ocnt--;
                    }
                }
                else
                {
                    // sum is odd
                    if (ocnt)
                    {
                        win = 1;
                        ocnt--;
                    }
                    else
                    {
                        ecnt--;
                    }
                }

                turn = 2;
            }
            else
            {
                if (win == 2)
                {
                    // sum is odd
                    if (ecnt)
                    {
                        ecnt--;
                    }
                    else
                    {
                        win = 1;
                        ocnt--;
                    }
                }
                else
                {
                    // sum is even
                    if (ocnt)
                    {
                        ocnt--;
                        win = 2;
                    }
                    else
                    {
                        ecnt--;
                    }
                }

                turn = 1;
            }
        }

        cout << win << endl;
    }

    return 0;
}