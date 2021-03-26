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
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int rooms[10];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    REP(i, 0, n)
    {
        if (s[i] == 'L')
        {
            REP(i, 0, 10)
            if (rooms[i] == 0)
            {
                rooms[i] = 1;
                break;
            }
        }
        else if (s[i] == 'R')
        {
            for (int i = 9; i >= 0; i--)
                if (rooms[i] == 0)
                {
                    rooms[i] = 1;
                    break;
                }
        }
        else
        {
            rooms[s[i] - '0'] = 0;
        }
    }

    REP(i, 0, 10)
        cout << rooms[i];
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