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

#define maxN 30001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        power >>= 1;
    }
    return res;
}

int n, q;
int arr[maxN];
int version[maxN];
int last[1000001];
const int sz = 10000000;
int temp;

struct node
{
    int l, r, sum;

    node()
    {
        l = r = sum = 0;
    }
} t[sz];

void extend(int v)
{
    t[v].l = ++temp;
    t[v].r = ++temp;
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        return;
    }

    int mid = (tl + tr) / 2;
    extend(v);
    build(t[v].l, tl, mid);
    build(t[v].r, mid + 1, tr);
}

int query(int node, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return t[node].sum;
    }

    int mid = (ss + se) / 2;
    return query(t[node].l, ss, mid, qs, qe) + query(t[node].r, mid + 1, se, qs, qe);
}

void update(int node, int ss, int se, int si, int val)
{
    if (ss == se)
    {
        t[node].sum = val;
        return;
    }

    int mid = (ss + se) / 2;

    if (si <= mid)
    {
        int old_l = t[node].l;
        int new_l = ++temp;
        t[new_l] = t[old_l];
        t[node].l = new_l;
        update(new_l, ss, mid, si, val);
    }
    else
    {
        int old_r = t[node].r;
        int new_r = ++temp;
        t[new_r] = t[old_r];
        t[node].r = new_r;
        update(new_r, mid + 1, se, si, val);
    }

    t[node].sum = t[t[node].l].sum + t[t[node].r].sum;
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i];

    REP(i, 1, n)
    {
        version[i] = ++temp;
        t[version[i]] = t[version[i - 1]];

        if (last[arr[i]])
        {
            update(version[i], 1, n, last[arr[i]], 0);
        }

        last[arr[i]] = i;
        update(version[i], 1, n, i, 1);
        // cout<<t[version[i]].sum<<endl;
    }

    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(version[r], 1, n, l, r) << endl;
    }
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

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}