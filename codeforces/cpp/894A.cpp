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

string s;
int nextloc(char c, int ini)
{
    for (int i = ini; i < s.size(); i++)
    {
        if (c == s[i])
        {
            return i;
        }
    }
    return s.size();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0, i, j, k, n;

    i = -1;
    cin >> s;
    n = s.size();

    while (i < n)
    {
        i = nextloc('Q', i + 1);
        j = i;
        while (j < n)
        {
            j = nextloc('A', j + 1);
            k = j;
            while (k < n)
            {
                k = nextloc('Q', k + 1);

                if (k != n)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}