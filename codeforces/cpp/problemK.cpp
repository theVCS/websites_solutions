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

    bool search2(string &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';

            if (temp->arr[index] == NULL || temp->arr[index]->cnt == 0)
                return false;

            temp = temp->arr[index];

            if (temp->endOfWord)
                return true;
        }

        return false;
    }

    bool search3(string &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';

            if (temp->arr[index] == NULL || temp->arr[index]->cnt == 0)
                return false;

            temp = temp->arr[index];
        }

        return (temp->endOfWord == false) || (temp->cnt > 1);
    }

    void del(string &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';
            temp = temp->arr[index];
            temp->cnt--;

            if (temp->cnt <= 0)
                temp->endOfWord = false;
        }
    }
};

const int blk = 2100;
const int arrSize = 100001;
const int querSize = 100001;

struct Query
{
    int l, r, t, index, type;
    string s;
} q[querSize];

struct Update
{
    int index;
    string new_y, prev_y;
} u[querSize];

bool cmp(Query const &a, Query const &b)
{
    if (a.t / blk != b.t / blk)
        return a.t < b.t;
    if (a.l / blk != b.l / blk)
        return a.l < b.l;
    return a.r < b.r;
}

string arr[arrSize];  // array which contains main data
string last[arrSize]; // last element present in the vector
bool use[arrSize];    // used in update

// extra variables

template <class TYPE>
class MOWithUpdate
{
    int n, m;
    int nq, nu;
    TYPE res;
    vector<TYPE> ans;
    TrieString trie;

public:
    MOWithUpdate() {}

    MOWithUpdate(int N, int M)
    {
        n = N, m = M;
        nq = nu = res = 0;
        ans.resize(M + 1);
    }

    void resize(int N, int M)
    {
        n = N, m = M;
        nq = nu = res = 0;
        ans.resize(M + 1);
    }

    void addQuery(int a, int b, int type, string &s)
    {
        nq++;
        q[nq].l = a;
        q[nq].r = b;
        q[nq].index = nq;
        q[nq].t = nu;
        q[nq].type = type;
        q[nq].s = s;
    }

    void addUpdate(int index, string &val)
    {
        nu++;
        u[nu].index = index;
        u[nu].new_y = val;
        u[nu].prev_y = last[index];
        last[index] = val;
    }

    void add(int index)
    {
        string ele = arr[index];
        use[index] = true;
        trie.insert(ele);
    }

    void remove(int index)
    {
        string ele = arr[index];
        use[index] = false;
        trie.del(ele);
    }

    void reflect_update(int index, string ele)
    {
        if (use[index] == false)
        {
            arr[index] = ele;
            return;
        }

        remove(index);
        arr[index] = ele;
        add(index);
    }

    void do_update(int index)
    {
        reflect_update(u[index].index, u[index].new_y);
    }

    void undo(int index)
    {
        reflect_update(u[index].index, u[index].prev_y);
    }

    void processQueries()
    {
        sort(q + 1, q + nq + 1, cmp);

        for (int i = 1, L = 2, R = 1, T = 0; i <= nq; i++)
        {
            while (T < q[i].t)
                do_update(++T);
            while (T > q[i].t)
                undo(T--);
            while (R < q[i].r)
                add(++R);
            while (L > q[i].l)
                add(--L);
            while (R > q[i].r)
                remove(R--);
            while (L < q[i].l)
                remove(L++);

            if (q[i].type == 2)
                ans[q[i].index] = trie.search2(q[i].s);
            else
                ans[q[i].index] = trie.search3(q[i].s);
        }
    }

    void showAns()
    {
        REP(i, 1, nq)
        if (ans[i])
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
};

void solve()
{
    int n, m;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        last[i] = arr[i];
    }

    cin >> m;
    MOWithUpdate<int> mo(n, m);

    REP(i, 1, m)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int index;
            string s;
            cin >> index >> s;
            mo.addUpdate(index, s);
        }
        else
        {
            int l, r;
            string s;
            cin >> l >> r >> s;
            mo.addQuery(l, r, type, s);
        }
    }

    mo.processQueries();
    mo.showAns();
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