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
vector<pii> arr[maxN];
int parent[maxN][19];
int maxi[maxN][19];
int mini[maxN][19];
int level[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    parent[node][0] = par;
    level[node] = l;

    for (pii child : arr[node])
    {
        if (child.first == par)
            continue;
        maxi[child.first][0] = child.second;
        mini[child.first][0] = child.second;
        dfs(child.first, node, l + 1);
    }
}

void preprocess()
{
    dfs();

    REP(j, 1, 18)
    {
        REP(i, 1, n)
        {
            if (parent[i][j - 1] == -1)
            {
                maxi[i][j] = max(maxi[i][j - 1], maxi[0][j - 1]);
                mini[i][j] = min(mini[i][j - 1], mini[0][j - 1]);
                parent[i][j] = -1;
            }
            else
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
                maxi[i][j] = max(maxi[i][j - 1], maxi[parent[i][j - 1]][j - 1]);
                mini[i][j] = min(mini[i][j - 1], mini[parent[i][j - 1]][j - 1]);
            }
        }
    }
}

int mx, mn;

int LCA(int a, int b)
{
    mx = 0, mn = INF;

    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        mx = max(mx, maxi[a][i]);
        mn = min(mn, mini[a][i]);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    RREP(i, 18, 0)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            mn = min({mn, mini[a][i], mini[b][i]});
            mx = max({mx, maxi[a][i], maxi[b][i]});
            a = parent[a][i], b = parent[b][i];
        }
    }

    mx = max(mx, maxi[a][0]);
    mn = min(mn, mini[a][0]);
    return parent[a][0];
}

void solve()
{
    cin >> n;

    int a, b, c;

    mini[1][0] = INF;

    REP(i, 1, n - 1)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c}), arr[b].push_back({a, c});
    }

    preprocess();

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int c = LCA(a, b);
        cout << mn << " " << mx << endl;
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

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}