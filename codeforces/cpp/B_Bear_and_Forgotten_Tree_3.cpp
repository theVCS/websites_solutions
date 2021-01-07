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

    int n, d, h;

    cin >> n >> d >> h;

    if (d > 2 * h || (n > 2 && d == 1))
    {
        cout << -1;
        return 0;
    }

    int v1, v2, v = 1;

    if (h == d)
    {
        v = 2;
    }
    

    for (int i = 1; i < h + 1; i++)
    {
        cout << i << " " << i + 1 << endl;
        v1 = i + 1;
    }

    d -= h;

    if (d--)
    {
        cout << 1 << " " << h + 2 << endl;
        v2 = h + 2;
    }

    for (int i = 1; i < d + 1; i++)
    {
        cout << i + h + 1 << " " << i + h + 2 << endl;
        v2 = h + i + 2;
    }

    while (v == v1 || v == v2)
    {
        v++;
    }

    for (int i = d + h + 2; i < n; i++)
    {
        cout << v << " " << i + 1 << endl;
    }

    return 0;
}