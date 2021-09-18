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
            res = mulmod(res,a,m);
        a = mulmod(a,a,m);
        power >>= 1;
    }
    return res;
}

int n, m;
bool checker[501][501];

bool isGuard(char c)
{
    return (c == '>' || c == '<' || c == '^' || c == 'v');
}

pii guard(char c)
{
    if(c == '>')
    {
        return {0,1};
    }
    else if(c=='<')
    {
        return {0,-1};
    }
    else if(c=='^')
    {
        return {-1,0};
    }
    else
    {
        return {1,0};
    }
}

void helper(int x, int y, pii d, vector<string>&b)
{
    while (true)
    {
        x = x + d.first;
        y = y + d.second;

        if(x < 0 || y < 0 || x >= n || y >= m || b[x][y]=='X' || isGuard(b[x][y]))return;

        checker[x][y]=true;
    }
}

bool vis[501][501];

bool isValid(int x, int y, vector<string>&B)
{
    if(x < 0 || y < 0 || x >= n || y >= m || B[x][y]=='X' || checker[x][y] || vis[x][y])
        return false;
    return true;
}

void dfs(int x, int y, vector<string>&B)
{
    vis[x][y]=true;

    REP(i,0,3)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if(isValid(X,Y,B))
        {
            dfs(X,Y,B);
        }
    }
}

bool solution(vector<string> &B) {
    // write your code in C++14 (g++ 6.2.0)
    n = B.size();
    m = B[0].size();

    int sx = -1, sy = -1;

    REP(i,0,n-1)
    {
        REP(j,0,m-1)
        {
            if(isGuard(B[i][j]))
            {
                pii dir = guard(B[i][j]);
                checker[i][j] = true;
                helper(i,j,dir,B);
            }

            if(B[i][j]=='A')sx=i,sy=j;
        }
    }

    if(checker[sx][sy] || checker[n-1][m-1])return false;
    dfs(sx,sy,B);
    return vis[n-1][m-1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> vec;

    REP(i, 0, n - 1)
    {
        string s;
        cin >> s;
        vec.push_back(s);
    }

    cout << solution(vec);
    return 0;
}