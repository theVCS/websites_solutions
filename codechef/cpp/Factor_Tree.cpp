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

int sieve[1000001];
ll inverse[2000001];

void init2()
{
    for (int i = 2; i < 1000001; i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j < 1000001; j += i)
            {
                if (!sieve[j])
                {
                    sieve[j] = i;
                }
            }
        }
    }

    inverse[0]=inverse[1]=1;
    REP(i, 2, 2000000)
    inverse[i] = ((inverse[mod%i])*(mod - mod/i)) % mod;
}

int n, m;
const int blk = 320;

// initialization
vector<int> arr[maxN];
int level[maxN], parent[maxN][19], val[maxN];

// flattening tree
int FT[2 * maxN], intime[maxN], outime[maxN], timer;
int nodeFre[maxN];

// answer
ll ans[maxN], res;

void euler(int node = 1, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    FT[timer] = node;
    parent[node][0] = par;
    level[node] = l;

    for (int child : arr[node])
    {
        if (child != par)
        {
            euler(child, node, l + 1);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

int lg;

void init(int n)
{
    euler();
    lg = log2(n);

    for (int j = 1; j < lg+1; j++)
    {
        for (int i = 1; i <= n; i++)
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

    for (int i = lg; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i], b = parent[b][i];
        }
    }

    return parent[a][0];
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}


struct query
{
    int l, r, lca, index;
    ll ord;

    inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
} Q[maxN];

bool cmp(query a, query b)
{
    return a.ord < b.ord;
}

int cnt[1000001];

void add(int index)
{
    int node = FT[index];
    nodeFre[node]++;

    if (nodeFre[node] == 1)
    {
        int _number = val[node];

        while (sieve[_number])
        {
            res = (res * inverse[cnt[sieve[_number]] + 1]) % mod;
            cnt[sieve[_number]] += 1;
            res = (res * (cnt[sieve[_number]] + 1)) % mod;
            _number = _number / sieve[_number];
        }
    }
    else if (nodeFre[node] == 2)
    {
        int _number = val[node];

        while (sieve[_number])
        {
            res = (res * inverse[cnt[sieve[_number]] + 1]) % mod;
            cnt[sieve[_number]] -= 1;
            res = (res * (cnt[sieve[_number]] + 1)) % mod;
            _number = _number / sieve[_number];
        }
    }
}

void remove(int index)
{
    int node = FT[index];
    nodeFre[node]--;

    if (nodeFre[node] == 1)
    {
        int _number = val[node];

        while (sieve[_number])
        {
            res = (res * inverse[cnt[sieve[_number]] + 1]) % mod;
            cnt[sieve[_number]] += 1;
            res = (res * (cnt[sieve[_number]] + 1)) % mod;
            _number = _number / sieve[_number];
        }
    }
    else if (nodeFre[node] == 0)
    {
        int _number = val[node];

        while (sieve[_number])
        {
            res = (res * inverse[cnt[sieve[_number]] + 1]) % mod;
            cnt[sieve[_number]] -= 1;
            res = (res * (cnt[sieve[_number]] + 1)) % mod;
            _number = _number / sieve[_number];
        }
    }
}

void solve()
{
    int a, b;
    scanf("%d", &n);
    // cin >> n;

    // clearing all data
    res = 1;
    timer = 0;
    REP(i, 1, n)
    {
        arr[i].clear();
        nodeFre[i] = 0;
        cnt[i] = 0;
    }

    REP(i, n + 1, 1000000)
    cnt[i] = 0;

    REP(i, 1, n - 1)
    {
        scanf("%d %d", &a, &b);
        // cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n)
    {
        scanf("%d", val + i);
        // cin >> val[i];
    }

    init(n);
    scanf("%d", &m);
    // cin >> m;

    REP(i, 1, m)
    {
        scanf("%d %d", &a, &b);
        // cin >> a >> b;

        if (intime[a] > intime[b])
            swap(a, b);

        int lca = LCA(a, b);

        if (lca == a)
        {
            Q[i].l = intime[a];
            Q[i].lca = -1;
        }
        else
        {
            Q[i].l = outime[a];
            Q[i].lca = lca;
        }

        Q[i].r = intime[b];
        Q[i].index = i;
        Q[i].calcOrder();
    }

    sort(Q + 1, Q + 1 + m, cmp);

    for (int i = 1, L = 1, R = 0; i <= m; i++)
    {
        while (L < Q[i].l)
            remove(L++);
        while (L > Q[i].l)
            add(--L);
        while (R < Q[i].r)
            add(++R);
        while (R > Q[i].r)
            remove(R--);

        int lca = Q[i].lca;

        if (lca > 0)
        {
            add(intime[lca]);
        }

        ans[Q[i].index] = res;

        if (lca > 0)
        {
            remove(intime[lca]);
        }
    }

    REP(i, 1, m)
    printf("%d\n", ans[i]);
    // cout << ans[i] << endl;
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

    init2();
    int t = 1;

    // cin >> t;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}