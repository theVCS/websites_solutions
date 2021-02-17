#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int blk = 700;

// initializing value
vector<int> arr[maxN];
ll col[maxN];

// flattening the tree
int FT[2 * maxN], intime[maxN], outime[maxN], timer;

// processing queries
int nodeFre[maxN], colFre[maxN], res;
int ans[maxN];

void init(int node = 1, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            init(child, node);
        }
    }
    outime[node] = ++timer;
    FT[timer] = node;
}

struct query
{
    int l, r, index;
} Q[maxN];

bool cmp(query a, query b)
{
    int x = a.l / blk, y = a.r / blk;
    return (x < y) || (x == y && a.r < b.r);
}

void add(int index)
{
    int node = FT[index];
    int c = col[node];

    if (++nodeFre[node] == 2 && ++colFre[c] == 1)
        res++;
}

void remove(int index)
{
    int node = FT[index];
    int c = col[node];

    if (--nodeFre[node] == 1 && --colFre[c] == 0)
        res--;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, compressed_val = 0, a, b;
    map<ll, int> mp;

    scanf("%d", &n);

    REP(i, 1, n + 1)
    {
        scanf("%lld", &col[i]);
        mp[col[i]];
    }

    // coordinate compression
    for (auto &it : mp)
    {
        it.second = ++compressed_val;
    }
    REP(i, 1, n + 1)
    {
        cout << col[i] << " " << mp[col[i]] << endl;
        col[i] = mp[col[i]];
    }

    REP(i, 0, n - 1)
    {
        scanf("%d %d", &a, &b);
        arr[a].push_back(b), arr[b].push_back(a);
    }

    init();

    REP(i, 1, n + 1)
    {
        Q[i].l = intime[i];
        Q[i].r = outime[i];
        Q[i].index = i;
    }

    sort(Q + 1, Q + 1 + n, cmp);

    for (int i = 1, L = 1, R = 0; i <= n; i++)
    {
        while (R < Q[i].r)
            add(++R);
        while (L > Q[i].l)
            add(--L);
        while (R > Q[i].r)
            remove(R--);
        while (L < Q[i].l)
            remove(L++);

        ans[Q[i].index] = res;
    }

    REP(i, 1, n + 1)
    // cout << ans[i] << " ";
    printf("%d ", ans[i]);

    return 0;
}