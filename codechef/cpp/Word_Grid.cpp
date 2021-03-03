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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> start[26], endt[26];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<string> sv;
        string s;

        REP(i, 0, n)
        {
            cin >> s;
            sv.push_back(s);

            start[s[0] - 'a'].push_back(i);
            endt[s.front() - 'a'].push_back(i);
        }

        int cnt = 0;

        REP(i, 0, 26)
        {
            if (start[i].size() >= 2)
            {
                
            }
        }
    }

    return 0;
}