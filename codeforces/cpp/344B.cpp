#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
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

    int a, b, c, sum, x, y, z;

    cin >> a >> b >> c;

    sum = a + b + c;

    if (sum % 2)
    {
        cout << "Impossible";
    }
    else
    {
        sum /= 2;

        x = sum - c;
        y = sum - a;
        z = sum - b;

        if (x >= 0 && y >= 0 && z >= 0)
        {
            cout << x << " " << y << " " << z;
        }
        else
        {
            cout << "Impossible";
        }
        }

    return 0;
}