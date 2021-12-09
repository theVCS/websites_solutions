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

string res;
int len;
const int sz = 26;

class TrieString
{
    struct Node
    {
        bool endOfWord;
        Node *arr[sz];
        int cnt;
        int wc;

        Node()
        {
            endOfWord = false;
            REP(i, 0, sz - 1)
            arr[i] = NULL;
            cnt = 0;
            wc = 0;
        }
    };

    Node *root;

public:
    TrieString()
    {
        root = new Node();
    }

    void insert(string &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';

            if (temp->arr[index] == NULL)
                temp->arr[index] = new Node();

            temp = temp->arr[index];
        }

        temp->endOfWord = true;
        temp->cnt++;
        temp->wc++;
    }

    int _dfs_(Node *temp)
    {
        if (temp == NULL)
            return 0;

        int mx = -INF;

        REP(i, 0, 25)
        mx = max(mx, _dfs_(temp->arr[i]));

        return temp->cnt = max(temp->cnt, mx);
    }

    void dfs()
    {
        int mx = _dfs_(root);
    }

    bool search(string &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            res.push_back(c);
            int index = c - 'a';

            if (temp->arr[index] == NULL || temp->arr[index]->cnt == 0)
                return false;

            temp = temp->arr[index];
        }

        len = temp->cnt;

        while (true)
        {

            int index = -1;

            REP(i, 0, 25)
            if (temp->arr[i] && temp->arr[i]->cnt == temp->cnt)
            {
                index = i;
                break;
            }

            if (temp->endOfWord && temp->wc == temp->cnt)
                break;

            if (index == -1)
                break;

            res.push_back(char('a' + index));
            temp = temp->arr[index];
        }

        return true;
    }
};

void solve()
{
    TrieString trie;
    int n, m;
    cin >> n;

    REP(i, 1, n)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }

    trie.dfs();
    cin >> m;

    REP(i, 1, m)
    {
        string s;
        cin >> s;

        res.clear();

        if (trie.search(s))
            cout << res << " " << len << endl;
        else
            cout << -1 << endl;
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