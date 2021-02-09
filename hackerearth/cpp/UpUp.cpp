// que4
// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/upup/

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

    string s;

    // while (cin >> s)
    // {
    //     if (s[0] > 90)
    //     {
    //         s[0] -= 32;
    //     }

    //     cout << s << " ";
    // }

    getline(cin, s);

    bool flag = true;

    for (char &c : s)
    {

        if (flag && c > 90)
        {
            c -= 32;
        }

        flag = false;

        if (c == ' ')
        {
            flag = true;
        }
    }

    cout << s;

    return 0;
}