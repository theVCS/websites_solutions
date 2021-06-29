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

#define maxN 100001
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

int n;
vector<int> arr[maxN];
ll dp[maxN];
ll a[maxN], b[maxN];

struct Line
{
    mutable ll m, b, p;
    bool operator<(const Line &o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

// for minimum value
struct LineContainer : multiset<Line, less<>>
{
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b)
    { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y)
    {
        if (y == end())
        {
            x->p = inf;
            return false;
        }
        if (x->m == y->m)
            x->p = x->b > y->b ? inf : -inf;
        else
            x->p = div(y->b - x->b, x->m - y->m);
        return x->p >= y->p;
    }
    void add(ll m, ll b)
    {
        auto z = insert({-m, -b, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x)
    {
        assert(!empty());
        auto l = *lower_bound(x);
        return -(l.m * x + l.b);
    }
};

void dfs(int node, int par, LineContainer &cht)
{
    bool leaf = true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        LineContainer l;

        dfs(child, node, l);

        for (auto e : l)
        {
            cht.add(-e.m, -e.b);
        }

        leaf = false;
    }

    if (leaf == false)
    {
        dp[node] = cht.query(a[node]);
    }

    cht.add(b[node], dp[node]);
}

void solve()
{
    int u, v;
    cin >> n;

    REP(i, 1, n)
    cin >> a[i];

    REP(i, 1, n)
    cin >> b[i];

    REP(i, 1, n - 1)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    LineContainer c;
    dfs(1, -1, c);

    REP(i, 1, n)
    cout << dp[i] << " ";
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