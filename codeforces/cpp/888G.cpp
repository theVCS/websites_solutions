#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 200001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int sz = 2;

class TrieBit
{
    struct Node
    {
        Node *arr[sz];
        int cnt;

        Node()
        {
            REP(i, 0, sz - 1)
            arr[i] = NULL;
            cnt = 0;
        }
    };

    Node *root;

public:
    TrieBit()
    {
        root = new Node();
    }

    void insert(ll s)
    {
        Node *temp = root;

        RREP(i, 63, 0)
        {
            if (s & (1LL << i))
            {
                if (temp->arr[1] == NULL)
                    temp->arr[1] = new Node();
                temp = temp->arr[1];
            }
            else
            {
                if (temp->arr[0] == NULL)
                    temp->arr[0] = new Node();
                temp = temp->arr[0];
            }

            temp->cnt++;
        }
    }

    bool search(ll s)
    {
        Node *temp = root;

        RREP(i, 63, 0)
        {
            if (s & (1LL << i))
            {
                if (temp->arr[1] == NULL || temp->arr[1]->cnt == 0)
                    return false;
                temp = temp->arr[1];
            }
            else
            {
                if (temp->arr[0] == NULL || temp->arr[0]->cnt == 0)
                    return false;
                temp = temp->arr[0];
            }
        }

        return true;
    }

    void del(ll s)
    {
        // if (search(s) == false)
        //     return;

        Node *temp = root;

        RREP(i, 63, 0)
        {
            if (s & (1LL << i))
            {
                temp = temp->arr[1];
            }
            else
            {
                temp = temp->arr[0];
            }

            temp->cnt--;
        }
    }

    ll calc(ll s)
    {
        Node *temp = root;
        ll ans = 0;

        RREP(i, 63, 0)
        {
            if (temp == NULL)
                return ans;

            if ((s & (1LL << i)) == 0)
            {
                if (temp->arr[0] && temp->arr[0]->cnt)
                {
                    temp = temp->arr[0];
                }
                else
                {
                    ans |= (1LL << i);
                    temp = temp->arr[1];
                }
            }
            else
            {
                if (temp->arr[1] && temp->arr[1]->cnt)
                {
                    temp = temp->arr[1];
                }
                else
                {
                    temp = temp->arr[0];
                    ans |= (1LL << i);
                }
            }
        }

        return ans;
    }
};
TrieBit trie;

ll arr[maxN];
map<int, int> mp;
vector<int> tree[maxN];

class DSU
{
    int n;
    vector<int> par;
    int cc;

public:
    DSU() {}

    DSU(int N)
    {
        n = N;
        cc = N;
        par.assign(n + 1, -1);
        REP(i, 1, n)
        tree[i].push_back(i);
    }

    void resize(int N)
    {
        n = N;
        cc = N;
        par.assign(n + 1, -1);
        REP(i, 1, n)
        tree[i].push_back(i);
    }

    int find(int a)
    {
        if (par[a] < 0)return a;
        else return par[a] = find(par[a]);
    }

    void merger(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (par[a] > par[b])
            swap(a, b);

        par[a] += par[b];
        par[b] = a;

        for (int node : tree[b])
            tree[a].push_back(node);

        cc--;
    }

    pair<ll, int> solve(ll node)
    {
        for (int child : tree[node])trie.del(arr[child]);
        pair<ll, int> res = {1LL << 50, 0};
        for (int child : tree[node])
        {
            ll v = trie.calc(arr[child]);

            if (v < res.first)
            {
                res.first = v;
                ll nodeBval = (v ^ arr[child]);
                res.second = mp[nodeBval];
            }
        }

        for (int child : tree[node])trie.insert(arr[child]);
        return res; //{min_xor,node}
    }

    int sz()
    {
        return cc;
    }
};

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n)
    {
        ll val;
        cin >> val;
        mp[val];
    }

    int timer = 0;
    for (auto &e : mp)
        e.second = ++timer, trie.insert(e.first), arr[timer] = e.first;

    n = timer;
    ll ans = 0;
    DSU dsu(n);

    while (dsu.sz() > 1)
    {
        REP(i, 1, n)
        {
            if (dsu.find(i) != i)continue;
            pair<ll, int> res = dsu.solve(i);
            int a = res.second, b = i;

            if (dsu.find(a) != dsu.find(b))
            {
                dsu.merger(a, b);
                ans += res.first;
            }
        }
    }

    cout << ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}