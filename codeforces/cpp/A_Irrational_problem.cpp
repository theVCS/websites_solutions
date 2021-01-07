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

    int p1, p2, p3, p4, a, b, smallest;

    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;

    smallest = min(min(p1, p2), min(p3, p4));

    if (a >= smallest)
    {
        cout << 0;
    }
    else if (a < smallest && b > smallest)
    {
        cout << smallest - a;
    }
    else
    {
        cout << b - a + 1;
    }

    return 0;
}