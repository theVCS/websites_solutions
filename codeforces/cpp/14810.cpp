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

    int t, px, py;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> px >> py;
        cin >> s;

        int l = 0, r = 0, u = 0, d = 0;
        int rl = 0, rr = 0, ru = 0, rd = 0;

        if (px > 0)
            rr = px;
        else
            rl = -1 * px;

        if (py > 0)
            ru = py;
        else
            rd = -1 * py;

        for (char k : s)
        {
            if (k == 'U')
                u++;
            else if (k == 'D')
                d++;
            else if (k == 'R')
                r++;
            else
                l++;
        }

        // cout << d << r << u << l << endl;
        // cout << rd << rr << ru << rl << endl;

        if (rl <= l && rr <= r && ru <= u && rd <= d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}