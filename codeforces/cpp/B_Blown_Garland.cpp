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

    string s, s1;
    int len, r = 0, g = 0, b = 0, y = 0;

    cin >> s;

    map<int, char> lb;
    map<int, int> fused;

    for (int i = 0; i < s.size(); i+=4)
    {
        len = min(4, int(s.size() - i + 1));
        s1 = s.substr(i, len);

        for (int j = 0; j < s1.size(); j++)
        {
            if (s1[j] != '!')
            {
                lb[j] = s1[j];
            }
            else
            {
                fused[j]++;
            }
        }
    }

    for(auto e : lb)
    {
        if (e.second == 'R')
        {
            r = fused[e.first];
        }
        else if (e.second == 'Y')
        {
            y = fused[e.first];
        }
        else if (e.second == 'B')
        {
            b = fused[e.first];
        }
        else
        {
            g = fused[e.first];
        }
    }

    cout << r << " " << b << " " << y << " " << g;

    return 0;
}