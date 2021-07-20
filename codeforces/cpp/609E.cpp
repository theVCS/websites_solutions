#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

struct point
{
    ll x, y, z;
    int index;

    point(long long tmp_x = 0, long long tmp_y = 0, long long tmp_z = 0)
    {
        x = tmp_x;
        y = tmp_y;
        z = tmp_z;
    }

    point operator+(point b)
    {
        return point(this->x + b.x, this->y + b.y, this->z + b.z);
    }

    point operator-(point b)
    {
        return point(this->x - b.x, this->y - b.y, this->z - b.z);
    }

    point operator*(long long val)
    {
        return point(this->x * val, this->y * val, this->z * val);
    }

    point operator/(long long val)
    {
        return point(this->x / val, this->y / val, this->z / val);
    }

    point &operator=(point b)
    {
        this->x = b.x;
        this->y = b.y;
        this->z = b.z;
        return *this;
    }

    point &operator+=(point b)
    {
        *this = *this + b;
        return *this;
    }

    point &operator-=(point b)
    {
        *this = *this - b;
        return *this;
    }

    point &operator*=(long long val)
    {
        (*this) = (*this) * val;
        return *this;
    }

    point &operator/=(long long val)
    {
        (*this) = (*this) / val;
        return *this;
    }

    bool operator==(point b)
    {
        if (this->x == b.x && this->y == b.y && this->z == b.z)
            return true;
        else
            return false;
    }
};
vector<point> points;

ll dot(point a, point b)
{
    ll ans = a.x * b.x + a.y * b.y + a.z * b.z;
    return ans;
}

point cross(point a, point b)
{
    point e;
    e.x = a.y * b.z - b.y * a.z;
    e.y = a.z * b.x - b.z * a.x;
    e.z = a.x * b.y - b.x * a.y;
    return e;
}

double magnitude(point a)
{
    return sqrt(dot(a, a));
}

double ang(point a, point b)
{
    return acos(dot(a, b) / (magnitude(a) * magnitude(b)));
}

double rad_to_deg(double val)
{
    return val * 180 / pi;
}

double deg_to_rad(double val)
{
    return val * pi / 180;
}

int direction(point pivot, point a, point b)
{
    long long t = cross((a - pivot), (b - pivot)).z;

    // t > 0, a x b is anti clockwise
    // t < 0, a x b is clockwise
    // t == 0, a and b are collinear

    return t;
}

#define maxN 200001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, m;
struct edge
{
    int a;
    int b;
    ll w;
    int index;
};
edge edg[maxN];
int par[maxN];

bool comp(edge a, edge b)
{
    return (a.w < b.w);
}

int find(int a)
{
    if (par[a] < 0)
        return a;
    else
        return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    if (par[a] > par[b])
        swap(a, b);

    par[a] += par[b];
    par[b] = a;
}

int level[maxN], parent[maxN][20], subSize[maxN];
vector<pair<int, ll>> tree[maxN];
pair<int, ll> specialChild[maxN];

// dfs call on given tree for pre-computation
void dfs(int node = 1, int par = -1, int l = 0)
{
    parent[node][0] = par;
    level[node] = l;
    subSize[node] = 1;

    int nodeX = -1, size = 0;
    ll weight = 0;

    for (pair<int, ll> child : tree[node])
    {
        if (child.first == par)
            continue;

        dfs(child.first, node, l + 1);

        subSize[node] += subSize[child.first];

        if (size < subSize[child.first])
            size = subSize[child.first], nodeX = child.first, weight = child.second;
    }

    // special child calculation
    specialChild[node] = {nodeX, weight};
}

void init()
{
    dfs();

    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
                parent[i][j] = -1;
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int timer, label[maxN], chainHead[maxN];
ll arr[maxN];

// heavy light decomposition part
void HLD(int node = 1, int par = -1, ll val = 0)
{
    label[node] = timer;
    arr[timer++] = val;

    int sc = specialChild[node].first;

    if (sc != -1)
    {
        chainHead[sc] = chainHead[node];
        HLD(sc, node, specialChild[node].second);
    }

    for (pii child : tree[node])
    {
        if (child.first == sc || child.first == par)
            continue;
        HLD(child.first, node, child.second);
    }
}

// segment tree
ll segTree[maxN * 4];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
    }
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return max(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

// LCA finder
int LCA(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
            a = parent[a][i], b = parent[b][i];
    }

    return parent[a][0];
}

// k-th ancestor finder
int kAncestor(int a, int d)
{
    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    return a;
}

// will give answer for the given query between node and ancestor
ll queryHLD(int node, int ances)
{
    ll res = 0, top = 0;

    while (level[node] > level[ances])
    {
        top = chainHead[node];

        if (level[top] <= level[ances])
        {
            top = kAncestor(node, level[node] - level[ances] - 1);
        }

        res = max(res, query(1, 1, n, label[top], label[node]));
        node = parent[top][0];
    }

    return res;
}

ll ans[maxN];

void solve()
{
    int a, b;

    cin >> n >> m;

    REP(i, 1, n)
    {
        par[i] = -1;
        chainHead[i] = i;
    }

    REP(i, 1, m)
    {
        cin >> edg[i].a >> edg[i].b >> edg[i].w;
        edg[i].index = i;
    }

    sort(edg + 1, edg + m + 1, comp);

    ll res = 0;

    REP(i, 1, m)
    {
        a = find(edg[i].a);
        b = find(edg[i].b);

        if (a != b)
        {
            tree[edg[i].a].push_back({edg[i].b, edg[i].w});
            tree[edg[i].b].push_back({edg[i].a, edg[i].w});
            merge(a, b);
            res+=edg[i].w;
        }
    }

    init();
    HLD();
    build(1, 1, n);

    REP(i, 1, m)
    {
        int lca = LCA(edg[i].a, edg[i].b);
        ans[edg[i].index] = res - max(queryHLD(edg[i].a, lca), queryHLD(edg[i].b, lca)) + edg[i].w;
    }

    REP(i, 1, m)
    cout << ans[i] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}