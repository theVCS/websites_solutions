#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200000
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, q, arr[maxN], fre[1000001], blk, ML, MR;
ll res[maxN], cnt;

struct edge
{
    int l, r, i;
};
edge Q[maxN];

bool cmp(edge a, edge b)
{
    if (a.l / blk != b.l / blk)
    {
        return (a.l / blk < b.l / blk);
    }
    return (a.r < b.r);
}

void add(int index)
{
    int freq = fre[arr[index]];

    cnt -= 1LL * freq * freq * arr[index];

    fre[arr[index]]++;

    freq = fre[arr[index]];

    cnt += 1LL * freq * freq * arr[index];
}

void remove(int index)
{
    int freq = fre[arr[index]];
    cnt -= 1LL * freq * freq * arr[index];

    fre[arr[index]]--;
    freq = fre[arr[index]];

    cnt += 1LL * freq * freq * arr[index];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    REP(i, 0, n)
    {
        cin >> arr[i];
    }

    blk = sqrt(n);

    REP(i, 0, q)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }

    sort(Q, Q + q, cmp);

    int L, R;
    ML = 0, MR = -1;
    REP(i, 0, q)
    {
        L = Q[i].l;
        R = Q[i].r;

        while (ML < L)
        {
            remove(ML);
            ML++;
        }

        while (ML > L)
        {
            ML--;
            add(ML);
        }

        while (MR > R)
        {
            remove(MR);
            MR--;
        }

        while (MR < R)
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