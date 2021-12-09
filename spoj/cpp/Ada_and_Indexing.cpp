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

const int sz = 26;

class TrieString
{
    struct Node
    {
        bool endOfWord;
        Node *arr[sz];
        int cnt;

        Node()
        {
            endOfWord = false;
            REP(i, 0, sz - 1)
            arr[i] = NULL;
            cnt = 0;
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
            temp->cnt++;
        }

        temp->endOfWord = true;
    }

    int search(string &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';

            if (temp->arr[index] == NULL || temp->arr[index]->cnt == 0)
                return 0;

            temp = temp->arr[index];
        }

        return temp->cnt;
    }

    void del(string &s)
    {
        if (search(s) == false)
            return;

        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';
            temp = temp->arr[index];
            temp->cnt--;
        }

        if (temp->cnt == 0)
            temp->endOfWord = false;
    }
};

void solve()
{
    TrieString trie;

    int n, m;
    cin >> n >> m;

    REP(i, 1, n)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }

    REP(i,1,m)
    {
        string s;
        cin>>s;
        cout<<trie.search(s)<<endl;
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