#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 300001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int pre_one[maxN];
int pre_zer[maxN];

void solve()
{
    string s, t;
    int n;
    cin >> n;
    cin >> s >> t;

    REP(i, 0, s.size())
    {
        pre_one[i] = (s[i] == '1');
        pre_zer[i] = (s[i] == '0');

        if (i)
        {
            pre_one[i] += pre_one[i - 1];
            pre_zer[i] += pre_zer[i - 1];
        }
    }

    int updated = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // now updating
        if (updated)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }

        if (s[i] != t[i])
        {
            if (pre_zer[i] == pre_one[i])
            {
                updated = (updated + 1) % 2;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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