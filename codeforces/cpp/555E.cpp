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

#define maxN 200001
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

int n, m, q;
int conn[maxN], cc;
vector<int> arr[maxN];
vector<int> strCon[maxN];
bool vis[maxN];

void strComFor(int node = 1, int par = -1)
{
    vis[node] = true;
    conn[node] = cc;
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
            strComFor(child, node);
            strCon[node].push_back(child);
        }
    }
}

bool onStack[maxN];
int intime[maxN], low[maxN], timer;
stack<int> st;
int id[maxN], scc;

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

            id[ut] = scc;

            if (ut == node)
            {
                break;
            }
        }
    }
}

vector<int> tree[maxN];

void treeFormer(int node = 1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (vis[child])
            continue;
        else
        {
            treeFormer(child);

            if (id[node] != id[child])
            {
                tree[id[node]].push_back(id[child]);
                tree[id[child]].push_back(id[node]);
                // cout<<id[node]<<" "<<id[child]<<endl;
                // cout<<node<<" "<<child<<endl;
            }
        }
    }
}

int parent[maxN][19];
int level[maxN];

void dfsTree(int node = 1, int par = -1, int l = 0)
{
    vis[node] = true;
    parent[node][0] = par;
    level[node] = l;

    for (int child : tree[node])
    {
        if (child == par)
            continue;
        dfsTree(child, node, l + 1);
    }
}

void preprocess()
{
    REP(i, 1, scc)
    if (vis[i] == false)
        dfsTree(i);

    REP(j, 1, 18)
    {
        REP(i, 1, scc)
        {
            if (parent[i][j - 1] == -1)
            {
                parent[i][j] = -1;
            }
            else
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    RREP(i, 18, 0)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
            a = parent[a][i], b = parent[b][i];
    }

    return parent[a][0];
}

int up[maxN], down[maxN];

bool check(int node)
{
    vis[node] = true;

    for (int child : tree[node])
    {
        if (vis[child])
            continue;
        if (check(child) == false)
            return false;
        up[node] += up[child], down[node] += down[child];
    }

    return (up[node] == 0 || down[node] == 0);
}

void solve()
{
    int u, v;
    cin >> n >> m >> q;

    REP(i, 1, m)
    {
        cin >> u >> v;
        arr[u].push_back(v), arr[v].push_back(u);
    }

    REP(i, 1, n)
    if (vis[i] == false)
    {
        cc++;
        strComFor(i);
    }

    REP(i, 1, n)
    vis[i] = false;

    REP(i, 1, n)
    {
        if (vis[i] == false)
            dfs(i);
    }

    REP(i, 1, n)
    {
        vis[i] = false;
    }

    REP(i, 1, n)
    {
        if (vis[i] == false)
            treeFormer(i);
    }

    REP(i, 1, scc)
    vis[i] = false;

    preprocess();

    while (q--)
    {
        cin >> u >> v;

        if (conn[u] != conn[v])
        {
            cout << "No";
            return;
        }

        u = id[u], v = id[v];

        if(u == v)continue;
    
        int lca = LCA(u, v);
        up[u]++, up[lca]--;
        down[v]++, down[lca]--;
    }

    REP(i, 1, scc)
    vis[i] = false;

    REP(i, 1, scc)
    {
        if (vis[i] == false)
        {
            if (check(i) == false)
            {
                cout << "No";
                return;
            }
        }
    }

    cout << "Yes";
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