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

int n, m, s, e;
ll cost[maxN];
vector<pii>arr[maxN];
ll costSum[maxN];

bool vis[maxN], onStack[maxN];
int intime[maxN], low[maxN], timer, scc;
stack<int> st;
int id[maxN];

void tarjan(int node)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;
    onStack[node] = true;
    st.push(node);

    for (pii child : arr[node])
    {
        if (vis[child.first] && onStack[child.first])
        {
            low[node] = min(low[node], intime[child.first]);
        }
        else if (!vis[child.first])
        {
            tarjan(child.first);

            if (onStack[child.first])
            {
                low[node] = min(low[node], low[child.first]);
            }
        }
    }

    if (intime[node] == low[node])
    {
        scc++;

        while (true)
        {
            int ut = st.top();
            st.pop();
            onStack[ut] = false;

            id[ut] = scc;
            costSum[scc] += cost[ut];

            if (ut == node)
            {
                break;
            }
        }
    }
}

vector<int>condGraph[maxN];
bool edgeChecker[maxN];

void condGrapher(int node)
{
    vis[node] = true;

    for(pii child: arr[node])
    {
        if(id[node] != id[child.first] && edgeChecker[child.second] == false)
        {
            edgeChecker[child.second] = true;
            // cout<<id[node]<<" "<<id[child.first]<<endl;
            condGraph[id[node]].push_back(id[child.first]);
        }

        if(vis[child.first])continue;
        condGrapher(child.first);
    
    }
}

ll ans;
ll dp[maxN];

ll dfs0(int node, int par = -1)
{
    if(dp[node] != -1)return dp[node];

    vis[node] = true;
    
    if(node == e)
    {
        return dp[node] = costSum[e];
    }
    
    ll ans = 0;

    for(int child: condGraph[node])
    {
        if(child == par)continue;
        ans = max(ans, dfs0(child, node));
    }

    return dp[node] = ans + costSum[node];
}

void solve()
{
    cin >> n >> m >> s >> e;
    REP(i,1,n)cin >> cost[i];

    int u, v;

    REP(i,1,m)
    {
        cin >> u >> v;
        arr[u].push_back({v,i});
    }

    REP(i,1,n)
    {
        if(!vis[i])tarjan(i);
    }

    REP(i,1,n)
    {
        vis[i]=false;
    }

    REP(i,1,n)
    if(!vis[i])
    condGrapher(i);

    s = id[s];
    e = id[e];

    REP(i,1,scc)vis[i] = false, dp[i] = -1;

    cout<<dfs0(s);
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