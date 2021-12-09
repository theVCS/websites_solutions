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
        int cnt;

        Node()
        {
            REP(i, 0, sz - 1)
            arr[i] = NULL;
            cnt = 0;
        }
    };

public:
    Node *root;

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
        if (search(s) == false)
            return;

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

    ll calc(int i, Node *temp, int x)
    {
        if (temp == NULL || temp->cnt == 0)
            return 0;
        else if (i == 0)
        {
            return x;
        }
        else
        {
            ll l = calc(i - 1, temp->arr[0], 0);
            ll r = calc(i - 1, temp->arr[1], 1);
            return max({l, r, l ^ r}) + x * (1LL << i);
        }
    }

    ll cal()
    {
        return max(calc(63, root->arr[0], 0), calc(63, root->arr[1], 1));
    }
};

void solve()
{
    TrieBit trie;

    trie.insert(0);

    int n;
    cin >> n;

    int x;

    REP(i, 1, n)
    {
        cin >> x;

        if (x > 0)
            trie.insert(x);
        else
            trie.del(-x);

        cout << trie.cal() << endl;
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