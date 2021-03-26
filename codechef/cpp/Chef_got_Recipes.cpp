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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll fre[32];

void solve()
{
    int n;
    cin >> n;

    string s;

    REP(i, 0, n)
    {
        cin >> s;

        int mask = 0;

        for (char c : s)
        {
            if (c == 'a')
                mask |= 1;
            else if (c == 'e')
                mask |= 2;
            else if (c == 'i')
                mask |= 4;
            else if (c == 'o')
                mask |= 8;
            else if (c == 'u')
                mask |= 16;

            if (mask == 31)
                break;
        }

        fre[mask]++;
    }

    ll res = 0;

    REP(i, 0, 31)
    {
        REP(j, i + 1, 32)
        {
            if ((i | j) == 31)
            {
                res = res + fre[i] * fre[j];
            }
        }

        fre[i] = 0;
    }

    res += (fre[31] * (fre[31] - 1)) / 2;
    fre[31] = 0;
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}