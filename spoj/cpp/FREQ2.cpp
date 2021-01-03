#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100000
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, blk, arr[maxN];
vector<map<int, int>> fre[310];

void init()
{
    map<int, int> res;

    REP(i, 0, n)
    {
        res[arr[i]]++;
        if ((i + 1) % blk == 0)
        {
            fre[i / blk].push_back(res);
            res.clear();
        }
    }

    if (n % blk != 0)
        fre[n / blk].push_back(res);
}

int sqDec(int l, int r)
{
    int lb = l / blk;
    int rb = r / blk;
    int res = INT_MIN;
    map<int, int> checker;

    if (lb == rb)
    {
        REP(i, l, r + 1)
        {
            checker[arr[i]]++;
            res = max(checker[arr[i]], res);
        }
    }
    else
    {
        for (int i = l; i < (lb + 1) * blk; i++)
        {
            checker[arr[i]]++;
            res = max(res, checker[arr[i]]);
        }

        for (int i = lb + 1; i < rb; i++)
        {
            for (map<int, int> k : fre[i])
            {
                for (auto e : k)
                {
                    checker[e.first] += e.second;
                    res = max(res, checker[e.first]);
                }
            }
        }

        for (int i = rb * blk; i <= r; i++)
        {
            checker[arr[i]]++;
            res = max(res, checker[arr[i]]);
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, a, b;

    cin >> n >> q;
    blk = sqrt(n);

    REP(i, 0, n)
    cin >> arr[i];

    init();

    while (q--)
    {
        cin >> a >> b;
        cout << sqDec(a, b) << endl;
    }

    return 0;
}