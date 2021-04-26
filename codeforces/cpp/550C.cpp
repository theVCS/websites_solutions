#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int num;

    REP(i, 0, n - 1)
    {
        num = s[i] - '0';

        if (num == 8 || num == 0)
        {
            cout << "YES" << endl;
            cout << num;
            return;
        }

        if (s.size() > 1)
            REP(j, i + 1, n - 1)
            {
                num = (s[i] - '0') * 10 + (s[j] - '0');

                if (num % 8 == 0)
                {
                    cout << "YES" << endl;
                    cout << num;
                    return;
                }

                if (s.size() > 2)
                    REP(k, j + 1, n - 1)
                    {
                        num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');

                        if (num % 8 == 0)
                        {
                            cout << "YES" << endl;
                            cout << num;
                            return;
                        }
                    }
            }
    }

    cout << "NO";
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}