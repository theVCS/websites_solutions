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

#define maxN 1001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(3) << x
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

int n, r, w, u, v;

struct edge
{
    int a;
    int b;
    ll w;
    int type;
};
edge arr[maxN * maxN];
int par[maxN];
int conn;

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

    // conn -= 2;
    par[a] += par[b];
    par[b] = a;
    conn--;
}

bool cmp(edge &a, edge &b)
{
    return a.w < b.w;
}

// 0-utp
// 1-optical

void solve()
{
    points.clear();
    cin >> n >> r >> w >> u >> v;

    conn = n;

    REP(i, 1, n)
    {
        point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    int m = 0;

    REP(i, 0, n - 1)
    {
        REP(j, i + 1, n - 1)
        {
            m++;

            arr[m].a = i + 1, arr[m].b = j + 1;

            if (dot(points[j] - points[i], points[j] - points[i]) <= r * r)
            {
                // if (u < v)
                arr[m].type = 0, arr[m].w = dot(points[j] - points[i], points[j] - points[i]) * u * u;
                // else
                // arr[m].type = 1, arr[m].w = dot(points[j] - points[i], points[j] - points[i]) * v * v;
            }
            else
            {
                arr[m].type = 1;
                arr[m].w = dot(points[j] - points[i], points[j] - points[i]) * v * v;
            }
        }
        par[i + 1] = -1;
    }

    sort(arr + 1, arr + 1 + m, cmp);
    double sum[2] = {0, 0};

    REP(i, 1, m)
    {
        if (conn == w)
            break;
        int a = find(arr[i].a);
        int b = find(arr[i].b);

        if (a != b)
        {
            sum[arr[i].type] += sqrt(arr[i].w);
            merge(a, b);
        }
    }

    printd(sum[0]) << " " << sum[1] << endl;
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

    cin >> t;

    // while (t--)
    REP(i, 1, t)
    {
        cout << "Caso #" << i << ": ";
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}