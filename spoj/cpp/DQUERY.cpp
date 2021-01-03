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

const int blk = 555;
int n, q, fre[1000001], cnt, arr[30000], ML, MR, res[200000];

struct query
{
    int l, r, i;
};
query Q[200000];

void add(int index)
{
    if (fre[arr[index]] == 0)
    {
        cnt++;
    }

    fre[arr[index]]++;
}

bool cmp(query a, query b)
{
    if (a.l / blk != b.l / blk)
    {
        return (a.l / blk) < (b.l / blk);
    }
    return (a.r < b.r);
}

void remove(int index)
{
    fre[arr[index]]--;

    if (fre[arr[index]] == 0)
    {
        cnt--;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    REP(i, 0, n)
    cin >> arr[i];

    cin >> q;

    REP(i, 0, q)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }

    sort(Q, Q + q, cmp);

    ML = 0, MR = -1;
    REP(i, 0, q)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while (L < ML)
        {
            ML--;
            add(ML);
        }

        while (L > ML)
        {
            remove(ML);
            ML++;
        }

        while (R < MR)
        {
            remove(MR);
            MR--;
        }

        while (R > MR)
        {
            MR++;
            add(MR);
        }

        res[Q[i].i] = cnt;
    }

    REP(i, 0, q)
    cout << res[i] << endl;

    return 0;
}