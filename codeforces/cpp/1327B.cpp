#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool vis[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, sizeK, prince, dau;
    bool flag = true;

    cin >> t;

    while (t--)
    {
        cin >> n;

        dau = 0;

        REP(i, 1, n + 1)
        {
            flag = true;
            cin >> sizeK;

            REP(j, 1, sizeK + 1)
            {
                cin >> prince;

                if (!vis[prince] && flag)
                {
                    vis[prince] = true;
                    flag = false;
                }
            }

            if (flag)
            {
                dau = i;
            }
        }

        REP(i, 1, n + 1)
        {
            if (!vis[i])
            {
                prince = i;
            }
            vis[i] = false;
        }

        if (dau)
        {
            cout << "IMPROVE" << endl;
            cout << dau << " " << prince << endl;
        }
        else
        {
            cout << "OPTIMAL" << endl;
        }
    }

    return 0;
}