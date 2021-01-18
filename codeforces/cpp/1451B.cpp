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

    int t, n, m, l, r;
    string st;
    bool flag;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        cin >> st;

        while (m--)
        {
            flag = false;
            cin >> l >> r;

            for (int i = 0; i < l - 1; i++)
            {
                if (st[i] == st[l - 1])
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                for (int i = r; i < st.size(); i++)
                {
                    if (st[i] == st[r - 1])
                    {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}