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

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

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
int arr[101][101];
bool vis[101][101];
int ans;

priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

bool isValid(int x, int y, int val)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || arr[x][y] > val)
        return false;
    return true;
}

bool isPushable(int x, int y, int val)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y])
        return false;
    return arr[x][y] > val;
}

bool isBorder(int x, int y)
{
    if (x == 1 || x == n || y == 1 || y == m)
        return true;
    return false;
}

void dfs(int x, int y, int val)
{
    vis[x][y] = true;

    if (isBorder(x, y) == false)
    {
        ans += val - arr[x][y];
    }

    REP(i, 0, 3)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (isPushable(X, Y, val))
        {
            pq.push({arr[X][Y], {X, Y}});
        }

        if (isValid(X, Y, val))
        {
            dfs(X, Y, val);
        }
    }
}

void solve()
{
    ans = 0;

    cin >> n >> m;

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            cin >> arr[i][j];
            vis[i][j] = false;

            if (i == 1 || i == n || j == 1 || j == m)
            {
                pq.push({arr[i][j], {i, j}});
            }
        }
    }

    while (!pq.empty())
    {
        pair<int, pii> ele = pq.top();
        // cout<<ele.second.first<<" "<<ele.second.second<<endl;
        pq.pop();
        if (vis[ele.second.first][ele.second.second] == false)
            dfs(ele.second.first, ele.second.second, ele.first);
    }

    cout << ans << endl;
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

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}