#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int treeNode = 100001;
vector<int> tree[treeNode];

// for lca finding
int level[treeNode], parent[treeNode][19];

// euler tree tour technique
int FT[2 * treeNode], intime[treeNode], outime[treeNode], timer;

class Tree
{
    int n;

public:
    Tree() {}

    Tree(int N)
    {
        n = N;
    }

    void resize(int N)
    {
        n = N;
    }

    void addEdge(int a, int b)
    {
        tree[a].push_back(b), tree[b].push_back(a);
    }

    void euler(int node = 1, int par = -1, int l = 0)
    {
        // euler tree tour technique
        intime[node] = ++timer;
        FT[timer] = node;

        // lca
        parent[node][0] = par;
        level[node] = l;

        for (int child : tree[node])
        {
            if (child == par)
                continue;
            euler(child, node, l + 1);
        }

        // euler tree tour technique
        outime[node] = ++timer;
        FT[timer] = node;
    }

    void init()
    {
        euler();

        // lca portion
        for (int j = 1; j < 19; j++)
            for (int i = 1; i <= n; i++)
                if (parent[i][j - 1] == -1)
                    parent[i][j] = -1;
                else
                    parent[i][j] = parent[parent[i][j - 1]][j - 1];
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
            if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
                a = parent[a][i], b = parent[b][i];

        return parent[a][0];
    }
};

void solve()
{
	int n;
    cin>>n;
    Tree tree(n);
    int a,b;

    REP(i,1,n-1)
    {
        cin>>a>>b;
        tree.addEdge(a,b);
    }

    tree.init();

    int q;
    cin>>q;

    while (q--)
    {
        int a,g;
        cin>>a>>g;
        int lca = tree.LCA(a,g);
        int d = level[a]+level[g]-2*level[lca];
        if(d & 1)
        {
            cout<<"Aditya"<<endl;
        }
        else
        {
            cout<<"Gungun"<<endl;
        }
    }
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