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

template <class T>
class Treap
{
    struct Node
    {
        int sz;
        T key, prior;
        Node *left, *right;
        Node() {}
        Node(T key) : key(key), prior(rand()), left(NULL), right(NULL) {}
        Node(T key, T prior) : key(key), prior(prior), left(NULL), right(NULL) {}
    };

    Node *root;

public:
    Treap()
    {
        root = NULL;
    }

    int cnt(Node *root)
    {
        return root ? (root->sz ? 0);
    }

    void refresh(Node *root)
    {
        if (root)
            root->sz = 1 + cnt(root->left) + cnt(root->right);
    }

    void split(Node *root, T key, Node *&left, Node *&right)
    {
        if (root == NULL)
            left = right = NULL;
        else if (root->key <= key)
            split(root->right, key, root->right, right), left = root;
        else
            split(root->left, key, left, root->left), right = root;

        refresh(root);
    }

    pair<Node *, Node *> split(T k)
    {
        Node *left, *right;
        split(root, k, left, right);
        return {left, right}; // left <= k && right > k
    }

    Node *merge(Node *l, Node *r)
    {
        // condition -> X values in one tree must be <= other
        if (!l || !r)
        {
            refresh(l);
            refresh(r);
            return l ? l : r;
        }
        if (l->prior < r->prior)
            swap(l, r);

        Node *lt, *rt;
        split(root, l->key, lt, rt);
        l->l = merge(l->l, lt);
        l->r = merge(l->r, rt);
        refresh(l);
        return l;
    }

    Node *search(Node *root, T K)
    {
        if (root == NULL)
            return NULL;
        else if (root->key == K)
            return root;
        else if (root->key < K)
            return search(root->right, K);
        else
            return search(root->left, K);
    }

    Node *search(T K)
    {
        return search(root, K);
    }

    void insert(Node *&root, Node *item)
    {
        if (root == NULL)
            root = item;
        else if (root->prior < item->prior)
            split(root, item->key, item->left, item->right), t = item;
        else
            insert((root->key <= item->key ? root->right : root->left), item);

        refresh(root);
    }

    void insert(T key, T prior = -1)
    {
        if (prior < 0)
            insert(root, Node(key));
        else
            insert(root, Node(key, prior));

        refresh(root);
    }

    void unite(Node *root, Node *left, Node *right)
    {
        if (left == NULL || right == NULL)
            return t = (l ? l : r);
        else if (left->prior > right->prior)
            unite(left->right, left->right, r), root = left;
        else
            unite(right->left, left, right->left), root = right;

        refresh(root);
    }

    void erase(Node *root, T key)
    {
        if (root->key == key)
        {
            Node *item = root;
            unite(root, root->left, root->right);
            delete item;
        }
        else
            erase((root->key > key) ? root->left : root->right, key);

        refresh(root);
    }

    void erase(T key)
    {
        erase(root, key);
    }
};

void solve()
{
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