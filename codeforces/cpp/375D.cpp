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

const int blk = 997;
int col[maxN], intime[maxN], outime[maxN], FT[2 * maxN], timer, ML, MR, fre[maxN], ele[maxN], ff[maxN], f[110];
vector<int> arr[maxN];

void dfs(int node, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

struct query
{
    int l;
    int r;
    int ind;
    int k;
};
query Q[maxN];

bool cmp(query a, query b)
{
    int x = a.l / blk;
    int y = b.l / blk;

    if (x != y)
    {
        return x < y;
    }

    if (x % 2)
    {
        return (a.r < b.r);
    }
    return (a.r > b.r);
}

void add(int ind)
{
    int node = FT[ind];
    int c = col[node];
    fre[node]++;

    if (fre[node] == 2)
    {
        ele[c]++;
        ff[ele[c]]++;
        ff[ele[c] - 1]--;
        f[ele[c] / blk]++;
        f[(ele[c] - 1) / blk]--;
    }
}

void remove(int ind)
{
    int node = FT[ind];
    int c = col[node];
    fre[node]--;

    if (fre[node] == 1)
    {
        ele[c]--;
        ff[ele[c]]++;
        ff[ele[c] + 1]--;
        f[(ele[c] + 1) / blk]--;
        f[ele[c] / blk]++;
    }
}

int getAns(int k, int n)
{
    int ans = 0;
    int l = k / blk;
    int r = n / blk;

    if (l == r)
    {
        REP(i, k, n + 1)
        {
            ans += ff[i];
        }
    }
    else
    {
        for (int i = k; i < (l + 1) * blk; i++)
        {
            ans += ff[i];
        }

        for (int i = l + 1; i < r; i++)
        {
            ans += f[i];
        }

        for (int i = r * blk; i <= n; i++)
        {
            ans += ff[i];
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, res[maxN];

    cin >> n >> m;

    REP(i, 1, n + 1)
    cin >> col[i];

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    REP(i, 0, m)
    {
        cin >> a >> b;
        Q[i].l = intime[a];
        Q[i].r = outime[a];
        Q[i].ind = i;
        Q[i].k = b;
    }

    sort(Q, Q + m, cmp);

    ML = 0, MR = -1;
    int L, R, k;
    REP(i, 0, m)
    {
        L = Q[i].l;
        R = Q[i].r;
        k = Q[i].k;

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

        while (R > MR)
        {
            MR++;
            add(MR);
        }

        while (R < MR)
        {
            remove(MR);
            MR--;
        }

        res[Q[i].ind] = getAns(k, n);
    }

    REP(i, 0, m)
    {
        cout << res[i] << endl;
    }

    return 0;
}