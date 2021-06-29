#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 20001
// #define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
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

    // t > 0, b is more anti clockwise than a
    // t < 0, b is more clockwise than a
    // t == 0, a and b are collinear

    return t;
}

int n;
int dis[maxN];
int level[maxN];
vector<int> atLevel[maxN];
set<int> arr[maxN];

void query(int node)
{
    cout << "? " << node << endl;
    fflush(stdout);

    REP(i, 1, n)
    {
        cin >> dis[i];
    }
}

int l;
int findParent()
{
    REP(i, 1, n)
    {
        if (level[i] == (l - 1) && dis[i] == 1)
            return i;
    }
}

void dfs(int node = 1, int par = -1)
{
    if (par != -1)
        cout << node << " " << par << endl;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
    }
}

void solve()
{
    cin >> n;

    // firstly taking node 1 as root and decide the level of nodes
    query(1);

    REP(i, 1, n)
    {
        level[i] = dis[i];
        atLevel[level[i]].push_back(i);

        if (level[i] == 1)
        {
            // there is edge b/w 1 and i
            arr[1].insert(i);
            arr[i].insert(1);
        }
    }

    // now we shall move to even levels
    l = 2;
    while (atLevel[l].size())
    {
        for (int node : atLevel[l])
        {
            if (arr[node].size())
                continue;

            query(node);

            REP(i, 1, n)
            {
                if (dis[i] == 1)
                {
                    arr[i].insert(node);
                    arr[node].insert(i);
                }
                else if (level[i] == l && dis[i] == 2)
                {
                    int par = findParent();
                    arr[i].insert(par);
                    arr[par].insert(i);
                }
            }
        }

        l += 2;
    }

    REP(node, 2, n)
    {
        bool flag = true;

        for (int child : arr[node])
        {
            if (level[child] < level[node])
                flag = false;
        }

        if (flag)
        {
            query(node);
            l = level[node];
            int par = findParent();
            arr[par].insert(node);
            arr[node].insert(par);

            REP(i,1,n)
            {
                if(level[i] == l && dis[i] == 2)arr[i].insert(par), arr[par].insert(i);
            }
        }
    }

    cout << "! " << endl;
    dfs();
    fflush(stdout);
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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