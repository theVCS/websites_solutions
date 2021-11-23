#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007

const int blk = 2100;
const int arrSize = 200001;
const int querSize = 100001;
const int freSize = 200001;

struct Query
{
    int l, r, t, index, lca;
} q[querSize];

struct Update
{
    int index, new_y, prev_y;
} u[2 * querSize];

bool cmp(Query const &a, Query const &b)
{
    if (a.t / blk != b.t / blk)
        return a.t < b.t;
    if (a.l / blk != b.l / blk)
        return a.l < b.l;
    return a.r < b.r;
}

int arr[arrSize];  // array which contains main data
int last[arrSize]; // last element present in the vector
bool use[arrSize]; // used in update
int fre[freSize];  // use to keep track of no of elements

// extra variables
map<int, int> mp;
const int treeNode = 100001;
int nodeLabel[arrSize];
int val[treeNode];
int nodeFre[treeNode];
int intime[treeNode], outime[treeNode];

class Tree
{
    int n;
    vector<int> tree[treeNode];
    int level[treeNode], parent[treeNode][19];
    int timer;

public:
    Tree(int N)
    {
        n = N;
        timer = 0;
    }

    void addEdge(int a, int b)
    {
        tree[a].push_back(b), tree[b].push_back(a);
    }

    void euler(int node = 1, int par = -1, int l = 0)
    {
        intime[node] = ++timer;
        arr[timer] = val[node];
        last[timer] = val[node];
        parent[node][0] = par;
        level[node] = l;
        nodeLabel[timer] = node;

        for (int child : tree[node])
        {
            if (child == par)
                continue;
            euler(child, node, l + 1);
        }

        outime[node] = ++timer;
        arr[timer] = val[node];
        last[timer] = val[node];
        nodeLabel[timer] = node;
    }

    void init()
    {
        euler();

        for (int j = 1; j < 19; j++)
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

        for (int i = 18; i >= 0; i--)
        {
            if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
            {
                a = parent[a][i], b = parent[b][i];
            }
        }

        return parent[a][0];
    }

    void swapper(int &a, int &b)
    {
        if (intime[a] > intime[b])
            swap(a, b);
    }

    int _intime_(int a)
    {
        return intime[a];
    }

    int _outime_(int a)
    {
        return outime[a];
    }
};

template <class TYPE>
class MOWithUpdate
{
    int n, m;
    int nq, nu;
    TYPE res;
    vector<TYPE> ans;

public:
    MOWithUpdate(int N, int M)
    {
        n = N, m = M;
        nq = nu = res = 0;
        ans.resize(M + 1);
    }

    void addQuery(int a, int b, int lca)
    {
        nq++;
        q[nq].l = a;
        q[nq].r = b;
        q[nq].index = nq;
        q[nq].t = nu;
        q[nq].lca = lca;
    }

    void addUpdate(int index, TYPE val)
    {
        nu++;
        u[nu].index = index;
        u[nu].new_y = val;
        u[nu].prev_y = last[index];
        last[index] = val;
    }

    void add(int index)
    {
        ll ele = arr[index];
        use[index] = true;
        int node = nodeLabel[index];

        nodeFre[node]++;

        if (nodeFre[node] == 1)
        {
            if (++fre[ele] == 1)
                res++;
        }

        if (nodeFre[node] == 2)
        {
            if (--fre[ele] == 0)
                res--;
        }
    }

    void remove(int index)
    {
        ll ele = arr[index];
        use[index] = false;
        int node = nodeLabel[index];

        nodeFre[node]--;

        if (nodeFre[node] == 1)
        {
            if (++fre[ele] == 1)
                res++;
        }

        if (nodeFre[node] == 0)
        {
            if (--fre[ele] == 0)
                res--;
        }
    }

    void reflect_update(int index, int ele)
    {
        if (use[index] == false)
        {
            arr[index] = ele;
            return;
        }

        remove(index);
        arr[index] = ele;
        add(index);
    }

    void do_update(int index)
    {
        reflect_update(u[index].index, u[index].new_y);
    }

    void undo(int index)
    {
        reflect_update(u[index].index, u[index].prev_y);
    }

    void processQueries()
    {
        sort(q + 1, q + nq + 1, cmp);

        for (int i = 1, L = 2, R = 1, T = 0; i <= nq; i++)
        {
            while (T < q[i].t)
                do_update(++T);
            while (T > q[i].t)
                undo(T--);
            while (R < q[i].r)
                add(++R);
            while (L > q[i].l)
                add(--L);
            while (R > q[i].r)
                remove(R--);
            while (L < q[i].l)
                remove(L++);

            ans[q[i].index] = res;

            if (q[i].lca != -1)
            {
                int index = intime[q[i].lca];
                add(index);
                ans[q[i].index] = res;
                remove(index);
            }

            // REP(i,1,n)
            //     cout<<arr[i]<<" ";
            // cout<<endl;
        }
    }

    void showAns()
    {
        REP(i, 1, nq)
        cout << ans[i] << endl;
    }

    void preprocess()
    {
        int timer = 0;

        for (auto &e : mp)
            e.second = ++timer;

        REP(i, 1, n)
        arr[i] = mp[arr[i]];

        REP(i, 1, nu)
        u[i].new_y = mp[u[i].new_y],
        u[i].prev_y = mp[u[i].prev_y];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    MOWithUpdate<int> mo(2 * n, m);
    Tree tree(n);

    REP(i, 1, n)
    {
        cin >> val[i];
        mp[val[i]];
    }

    REP(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        tree.addEdge(a, b);
    }

    tree.init();

    REP(i, 1, m)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
        {
            if(tree._intime_(a)>tree._intime_(b))swap(a,b);
            int lca = tree.LCA(a, b);

            if (lca == a)
                mo.addQuery(tree._intime_(a), tree._intime_(b), -1);
            else
                mo.addQuery(tree._outime_(a), tree._intime_(b), lca);
        }
        else
        {
            mp[b];
            mo.addUpdate(tree._intime_(a), b);
            mo.addUpdate(tree._outime_(a), b);
        }
    }

    mo.preprocess();
    mo.processQueries();
    mo.showAns();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("inputD.txt","r",stdin);
    // freopen("a.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}