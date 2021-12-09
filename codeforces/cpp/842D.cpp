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

const int sz = 2;

class TrieBit
{
    struct Node
    {
        Node *arr[sz];
        ll cnt;

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
        }
    }

    ll _dfs_(Node *root)
    {
        if (root == NULL)
            return 0;
        else
            return root->cnt = _dfs_(root->arr[0]) + _dfs_(root->arr[1]) + 1;
    }

    void dfs()
    {
        ll val = _dfs_(root);
    }

    ll calc(int x)
    {
        Node *temp = root->arr[0]->arr[0];
        ll ans = 0;

        RREP(i, 62, 0)
        {
            if (temp->cnt == (1LL << (i + 1)) - 1)
            {
                // cout << "Prince3" << endl;
                ans |= (1LL << i);
                break;
            }


            if (x & (1LL << (i - 1)))
            {
                if (temp->arr[1] == NULL)
                {
                    return ans;
                }

                if (temp->arr[1]->cnt != (1LL << i) - 1)
                {
                    temp = temp->arr[1];
                    continue;
                }

                ans |= (1LL << (i - 1));

                if (temp->arr[0] == NULL)
                {
                    return ans;
                }

                temp = temp->arr[0];
            }
            else
            {
                if (temp->arr[0] == NULL)
                {
                    return ans;
                }

                if (temp->arr[0]->cnt != (1LL << i) - 1)
                {
                    temp = temp->arr[0];
                    continue;
                }

                ans |= (1LL << (i - 1));

                if (temp->arr[1] == NULL)
                {
                    return ans;
                }

                temp = temp->arr[1];
            }
        }

        return ans;
    }
};

void solve()
{
    TrieBit trie;

    int n, m;
    cin >> n >> m;

    REP(i, 1, n)
    {
        int num;
        cin >> num;
        trie.insert(num);
    }

    trie.dfs();
    ll c = 0;
    // cout << trie.calc(1) << endl;

    REP(i, 1, m)
    {
        ll x;
        cin >> x;
        c = (c xor x);
        cout << trie.calc(c) << endl;
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