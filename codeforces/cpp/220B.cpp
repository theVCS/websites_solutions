#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
int f[310], n, blk;
map<ll, int> counter;

void init()
{
    int res = 0;

    REP(i, 0, n)
    {
        if ((i + 1) % blk == 0)
        {
            f[i / blk] = res;
            res = 0;
        }

        if (arr[i] == i)
        {
            res++;
        }
    }
    f[n / blk] = res;
}

int sqDec(int l, int r)
{
    l--, r--;
    int lb = l / blk;
    int rb = r / blk;
    int res = 0;

    if (lb == rb)
    {
        for (int i = lb; i <= r; i++)
        {
            if (arr[i] == i)
            {
                res++;
            }
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                if (arr[i] == i)
                {
                    res++;
                }
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;

    cin >> n >> m;

    blk = sqrt(n);

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    init();

    return 0;
}