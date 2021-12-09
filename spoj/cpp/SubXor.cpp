#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 100001
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

    ll calc(ll s, ll k)
    {
        Node *temp = root;
        ll ans = 0;

        RREP(i, 63, 0)
        {
            if (k & (1LL << i))
            {
                if (s & (1LL << i))
                {
                    if (temp->arr[1] && temp->arr[1]->cnt)
                        ans += temp->arr[1]->cnt;

                    if (temp->arr[0] && temp->arr[0]->cnt)
                        temp = temp->arr[0];
                    else
                        return ans;
                }
                else
                {
                    if (temp->arr[0] && temp->arr[0]->cnt)
                        ans += temp->arr[0]->cnt;

                    if (temp->arr[1] && temp->arr[1]->cnt)
                        temp = temp->arr[1];
                    else
                        return ans;
                }
            }
            else
            {
                if (s & (1LL << i))
                {
                    if (temp->arr[1] && temp->arr[1]->cnt)
                        temp = temp->arr[1];
                    else
                        return ans;
                }
                else
                {
                    if (temp->arr[0] && temp->arr[0]->cnt)
                        temp = temp->arr[0];
                    else
                        return ans;
                }
            }
        }

        return ans;
    }
};

int n, k;

void solve()
{
    cin >> n >> k;

    TrieBit trie;
    trie.insert(0);

    ll x = 0;
    ll ans = 0;
    ll val;

    REP(i, 1, n)
    {
        cin >> val;
        x = (x ^ val);
        ans += trie.calc(x, k);
        trie.insert(x);
        // cout << ans << " ";
    }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}