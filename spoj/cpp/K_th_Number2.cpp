#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN], rev[maxN];

struct node
{
    node *left, *right;
    int cnt;

    node(node *l, node *r, int c)
    {
        left = l, right = r, cnt = c;
    }
};

vector<node *> root;
int rootIndex;

void build(node *n, int ss, int se)
{
    if (ss != se)
    {
        int mid = (ss + se) / 2;

        n->left = new node(NULL, NULL, 0);
        n->right = new node(NULL, NULL, 0);

        build(n->left, ss, mid);
        build(n->right, mid + 1, se);
    }
}

void update(node *n, node *prev, int ss, int se, int qi)
{
    if (ss == se)
    {
        n->cnt++;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        n->right = prev->right;
        n->left = new node(NULL, NULL, 0);
        update(n->left, prev->left, ss, mid, qi);
    }
    else
    {
        n->left = prev->left;
        n->right = new node(NULL, NULL, 0);
        update(n->right, prev->right, mid + 1, se, qi);
    }

    n->cnt = n->left->cnt + n->right->cnt;
}

int query(node *a, node *b, int ss, int se, int k)
{
    if (ss == se)
        return ss;

    int mid = (ss + se) / 2;
    int r = a->left->cnt - b->left->cnt;

    if (r >= k)
        return query(a->left, b->left, ss, mid, k);
    else
        return query(a->right, b->right, mid + 1, se, k - r);
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m, a, b, c, compressed_val = 0;
    map<int, int> mp;

    scanf("%d %d", &n, &m);

    REP(i, 1, n + 1)
    {
        scanf("%d", arr + i);
        mp[arr[i]];
    }

    for (auto &it : mp)
    {
        it.second = ++compressed_val;
        rev[compressed_val] = it.first;
    }

    REP(i, 1, n + 1)
    arr[i] = mp[arr[i]];

    node *r;

    r = new node(NULL, NULL, 0);
    root.push_back(r);
    build(r, 1, n);

    REP(i, 1, n + 1)
    {
        rootIndex++;
        r = new node(NULL, NULL, 0);
        root.push_back(r);
        update(r, root[rootIndex - 1], 1, n, arr[i]);
    }

    while (m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", rev[query(root[b], root[a - 1], 1, n, c)]);
    }

    return 0;
}