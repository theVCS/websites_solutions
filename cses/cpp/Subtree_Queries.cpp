#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001

const int blk = 1000;

// initialization
ll val[maxN], last[maxN];
vector<int> arr[maxN];
int nu, nq;
int intime[maxN], outime[maxN], FT[2 * maxN], timer;

// processing queries
int nodeFre[maxN];
ll res, ans[maxN];
bool use[maxN];

void init(int node = 1, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            init(child, node);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

struct query
{
    int l, r, index, t, lb, rb;
} Q[maxN];

struct update
{
    int node;
    ll prev_val, new_val;
} U[maxN];

void add(int index)
{
    int node = FT[index];

    nodeFre[node]++;

    if (nodeFre[node] == 2)
    {
        use[node] = true;
        res += val[node];
        // cout << "added " << node << endl;
    }
}

void remove(int index)
{
    int node = FT[index];

    nodeFre[node]--;

    if (nodeFre[node] == 1)
    {
        use[node] = false;
        res -= val[node];
        // cout << "removed " << node << endl;
    }
}

void reflect_update(int node, ll v)
{
    if (!use[node])
    {
        val[node] = v;
        return;
    }
    res -= val[node];
    val[node] = v;
    res += val[node];
}

void do_update(int index)
{
    reflect_update(U[index].node, U[index].new_val);
}

void undo(int index)
{
    reflect_update(U[index].node, U[index].prev_val);
}

bool cmp(query a, query b)
{
    return (a.lb < b.lb) || (a.lb == b.lb && a.rb < b.rb) || (a.lb == b.lb && a.rb == b.rb && a.t < b.t);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, code, nod;
    ll v;

    scanf("%d %d", &n, &m);
    // cin >> n >> m;

    REP(i, 1, n + 1)
    scanf("%lld", val + i), last[i] = val[i];

    REP(i, 0, n - 1)
    {
        scanf("%d %d", &a, &b);
        // cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    init();

    REP(i, 1, m + 1)
    {
        scanf("%d", &code);
        // cin >> code;

        if (code == 1)
        {
            nu++;
            scanf("%d %lld", &nod, &v);
            // cin >> nod >> v;
            U[nu].node = nod;
            U[nu].prev_val = last[nod];
            U[nu].new_val = v;
            last[nod] = v;
        }
        else
        {
            nq++;
            scanf("%d", &nod);
            // cin >> nod;
            Q[nq].index = nq;
            Q[nq].l = intime[nod];
            Q[nq].r = outime[nod];
            Q[nq].t = nu;
            Q[nq].lb = intime[nod] / blk;
            Q[nq].rb = outime[nod] / blk;
        }
    }

    sort(Q + 1, Q + 1 + nq, cmp);

    for (int i = 1, L = 1, R = 0, T = 0; i <= nq; i++)
    {
        while (T < Q[i].t)
            do_update(++T);
        while (T > Q[i].t)
            undo(T--);
        while (R < Q[i].r)
            add(++R);
        while (L > Q[i].l)
            add(--L);
        while (R > Q[i].r)
            remove(R--);
        while (L < Q[i].l)
            remove(L++);

        ans[Q[i].index] = res;
    }

    REP(i, 1, nq + 1)
    printf("%lld\n", ans[i]);
    // cout << ans[i] << "\n";

    return 0;
}