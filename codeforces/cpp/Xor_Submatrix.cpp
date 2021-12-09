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

    ll calc(ll s)
    {
        Node *temp = root;
        ll ans = 0;

        RREP(i, 63, 0)
        {
            if (s & (1LL << i))
            {
                if (temp->arr[0] && temp->arr[0]->cnt)
                {
                    ans |= (1LL << i);
                    temp = temp->arr[0];
                }
                else
                {
                    temp = temp->arr[1];
                }
            }
            else
            {
                if (temp->arr[1] && temp->arr[1]->cnt)
                {
                    ans |= (1LL << i);
                    temp = temp->arr[1];
                }
                else
                {
                    temp = temp->arr[0];
                }
            }
        }

        return ans;
    }
};

int arr[1001];
int brr[1001];

void solve()
{
    TrieBit trie1, trie2, trie3, trie4;

    int n, m;
    cin >> n >> m;

    REP(i, 1, n)
    cin >> arr[i];

    REP(i, 1, m)
    cin >> brr[i];

    int c = 0;
    ll ans = 0;

    trie1.insert(0);
    trie2.insert(0);
    trie3.insert(0);
    trie4.insert(0);

    REP(i, 1, n)
    {
        c ^= arr[i];
        ans = max(ans, trie1.calc(c));
        trie1.insert(c);
    }

    c = 0;

    REP(i, 1, m)
    {
        c ^= brr[i];
        ans = max(ans, trie2.calc(c));
        trie2.insert(c);
    }

    c = 0;

    REP(i, 1, n)
    {
        c ^= arr[i];
        REP(j, 1, m)
        ans = max(ans, trie3.calc(c ^ brr[j]));
        trie3.insert(c);
    }

    c = 0;

    REP(i, 1, m)
    {
        c ^= brr[i];
        REP(j, 1, n)
        ans = max(ans, trie4.calc(c ^ arr[j]));
        trie4.insert(c);
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