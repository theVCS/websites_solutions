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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int res[maxN];

int main(int argc, char const *argv[])
{
    int n, m, a, b, c;

    scanf("%d %d", &n, &m);

    set<int> s;

    REP(i, 1, n + 1)
    s.insert(i);

    while (m--)
    {
        scanf("%d %d %d", &a, &b, &c);

        set<int>::iterator iter = s.lower_bound(a);

        vector<int> rm;

        while (iter != s.end())
        {
            int v = *iter;
            iter++;

            if (v > b)
                break;
            if (v != c)
                res[v] = c, s.erase(v);
        }
    }

    REP(i, 1, n + 1)
    printf("%d ", res[i]);

    return 0;
}