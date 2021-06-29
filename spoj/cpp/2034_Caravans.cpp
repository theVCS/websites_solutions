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

int n, m;
vector<int> arr[maxN];
int s, f, r;
int dist[maxN];
bool vis[maxN];
vector<int> parent[maxN];

void bfs()
{
    dist[f] = 0;
    queue<int> q;
    q.push(f);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : arr[node])
        {
            if (dist[child] > dist[node] + 1)
            {
                parent[child].clear();
                parent[child].push_back(node);
                dist[child] = dist[node] + 1;
                q.push(child);
            }
            else if (dist[child] == dist[node] + 1)
            {
                parent[child].push_back(node);
            }
        }
    }
}

void bfs2()
{
    vis[r] = true;
    queue<int> q;
    q.push(r);
    dist[r] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : arr[node])
        {
            if (vis[child])
                continue;
            dist[child] = dist[node] + 1;
            vis[child] = true;
            q.push(child);
        }
    }
}

int dp[maxN];

int maxDis(int node)
{
    if(node == f)
    {
        return dist[f];
    }
    else if (dp[node] != -1)
    {
        return dp[node];
    }
    else
    {
        int res = 0;

        for(int child: parent[node])
        {
            res = max(res, min(dist[node], maxDis(child)));
        } 

        return dp[node] = res;
    }
}

void solve()
{
    int u, v;
    cin >> n >> m;

    REP(i, 1, m)
    {
        cin >> u >> v;
        arr[u].push_back(v), arr[v].push_back(u);
    }

    cin >> s >> f >> r;

    REP(i, 1, n)
    dist[i] = INF;
    bfs();

    REP(i, 1, n)
    {
        dist[i] = INF;
        dp[i] = -1;
    }
    bfs2();

    cout <<maxDis(s);
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