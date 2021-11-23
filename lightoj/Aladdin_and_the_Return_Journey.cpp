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

#define maxN 30011
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

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

int n;
int genies[maxN];
vector<int>arr[maxN];
int intime[maxN], outime[maxN], ft[2*maxN], timer;
int parent[maxN][17], level[maxN];

void ett(int node=1, int par=-1, int lev = 0)
{
    intime[node]=++timer;
    ft[timer]=genies[node];
    parent[node][0] = par;
    level[node] = lev;

    for(int child: arr[node])
    {
        if(child==par)continue;
        ett(child,node,lev+1);
    }

    outime[node]=++timer;
    ft[timer]=-genies[node];
}

void init()
{
    ett();

    for (int j = 1; j < 17; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
            else
            {
                parent[i][j]=-1;
            }
            
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
    {
        swap(a, b);
    }

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
    {
        return a;
    }

    for (int i = 16; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

template <class T>
class FenwickTree
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    T query(int index)
    {
        T q = 0;

        while (index > 0)
        {
            q += BIT[index];
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] += val;
            index += (index & -index);
        }
    }

    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int lowerBound(T val)
    {
        // will find the lower bound index of val in BIT if monotonically increasing
        // https://codeforces.com/blog/entry/61364

        T q = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= n && q + BIT[pos + (1 << i)] < val)
            {
                q += BIT[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};


void solve()
{
    cin>>n;
    FenwickTree<ll>fet(2*n);
    timer=0;

    REP(i,1,n)
    {
        arr[i].clear();
        cin>>genies[i];
    }

    REP(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        u++,v++;
        arr[u].push_back(v), arr[v].push_back(u);
    }

    init();

    REP(i,1,timer)
    fet.update(i,ft[i]);

    int q;
    cin>>q;

    while(q--)
    {
        int type,x,y;
        cin>>type>>x>>y;

        if(type==0)
        {
            x++,y++;
            if(level[x]>level[x])swap(x,y);
            int lca = LCA(x,y);

            if(lca==x)
            {
                cout<<fet.query(intime[x],intime[y])<<endl;
            }
            else
            {
                cout<<fet.query(intime[lca],intime[x])+fet.query(intime[lca]+1,intime[y])<<endl;
            }
        }
        else
        {
            x++;
            int diff=y-genies[x];
            fet.update(intime[x],diff);
            fet.update(outime[x],-diff);
            genies[x]=y;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("inputD.txt","r",stdin);
    //freopen("a.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc,1,t)
    {
        cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}