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

#define maxN 10001
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
vector<int> strCon[maxN];
bool vis[maxN];

void strComFormer(int node = 1, int par = -1)
{
    vis[node] = true;
    int cnt = 0;

    for (int child : arr[node])
    {
        if (child == par && cnt == 0)
        {
            cnt++;
            continue;
        }
        else if (vis[child])
            strCon[node].push_back(child);
        else
        {
            strCon[node].push_back(child);
            strComFormer(child, node);
        }
    }
}

bool onStack[maxN];
int intime[maxN], low[maxN], timer;
int nodeId[maxN], scc;
stack<int> st;

void dfs(int node)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;
    onStack[node] = true;
    st.push(node);

    for (int child : strCon[node])
    {
        if (vis[child] && onStack[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else if (!vis[child])
        {
            dfs(child);

            if (onStack[child])
            {
                low[node] = min(low[node], low[child]);
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

            nodeId[ut] = scc;

            if (ut == node)
            {
                break;
            }
        }
    }
}

vector<int> tree[maxN];

void treeFormer(int node = 1, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (vis[child])
            continue;

        treeFormer(child, node);
        if (nodeId[node] != nodeId[child])
        {
            // cout<<node<<" "<<child<<endl;
            // cout<<nodeId[child]<<" "<<nodeId[node]<<endl;
            tree[nodeId[node]].push_back(nodeId[child]);
            tree[nodeId[child]].push_back(nodeId[node]);
        }
    }
}

int nodeX, dis = -1;

void dfs0(int node = 1, int par = -1, int d = 0)
{
    if (dis < d)
    {
        dis = d;
        nodeX = node;
    }

    for (int child : tree[node])
    {
        if (child == par)
            continue;
        dfs0(child, node, d + 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream filptr("input.txt");
    ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int u, v;

    filptr >> n >> m;

    REP(i, 1, m)
    {
        filptr >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    strComFormer();
    memset(vis, false, sizeof(vis));

    REP(i, 1, n)
    {
        if (vis[i] == false)
            dfs(i);
    }

    // REP(i,1,n)
    //     cout<<nodeId[i]<<" ";
    // cout<<endl;

    memset(vis, false, sizeof(vis));
    treeFormer();

    int nodea = -1, nodeb = -1;
    dfs0();
    nodea = nodeX;
    dis = -1;
    dfs0(nodeX);
    nodeb = nodeX;

    int ans1, ans2;

    REP(i, 1, n)
    {
        if (nodeId[i] == nodea)
        {
            ans1 = i;
            nodea = -1;
        }

        if (nodeId[i] == nodeb)
        {
            ans2 = i;
            nodeb = -1;
        }

        if (nodea == -1 && nodeb == -1)
            break;
    }

    outpter << ans1 << " " << ans2;

    filptr.close();
    outpter.close();

    return 0;
}