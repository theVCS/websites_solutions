#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 2e8 + 1
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll t[maxN/2];
ll cube[29];

void init()
{
    int i = 1;

    while (i < 29)
    {
        cube[i] = i * i * i;
        i++;
    }

    t[0] = t[1] = 0;
    i = 1;

    while(2 * i < maxN)
    {
        t[i] = cube[__builtin_ffsl(2 * i)] + t[i - 1];
        i++;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int cs;
    int n;

    scanf("%d", &cs);

    while (cs--)
    {
        scanf("%d", &n);
        printf("%lld\n", t[n/2]);
    }

    return 0;
}