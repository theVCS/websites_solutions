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
class FenwickTree
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree() {}

    FenwickTree(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    void resize(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    T query(int index)
    {
        T q = 0;

        while (index > 0)
        {
            q = max(q,BIT[index]);
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] = max(val,BIT[index]);
            index += (index & -index);
        }
    }

    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int lowerBound(T val)
    {
        // will find the lower bound index of val in BIT if monotonically increasing
        // https://codeforces.com/blog/entry/61364

        T q = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= n && q + BIT[pos + (1 << i)] < val)
            {
                q += BIT[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};

int lis(vector<int>&arr)
{
    FenwickTree<int>ft(400);
    int ans = 0;

    for(int ele: arr)
    {
        int res = ft.query(ele);
        ans=max(ans,res+1);
        ft.update(ele,res+1);
    }

    return ans;
}

struct card
{
    int val, index;

    card(int v, int i)
    {
        val = v;
        index = i;
    }
};

vector<card> cards[5];

bool cmp(card &a, card &b)
{
    return a.val < b.val;
}

void solve()
{
    int n, c, C;
    cin >> c >> n;
    C = c;

    REP(i, 1, n * c)
    {
        int c, v;
        cin >> c >> v;
        cards[c].push_back(card(v, i));
    }

    
    vector<int>per;
    REP(i,1,c)
    per.push_back(i), sort(all(cards[i]), cmp);
    
    int allPer = 1;
    while(C)allPer*=C,C--;
    
    int ans = INF;

    while (allPer--)
    {
        next_permutation(all(per));
        vector<int>arr;
        
        for(int c: per)
        {
            for(card ele: cards[c])
            {
                arr.push_back(ele.index);
            }
        }

        ans = min(ans,n*c-lis(arr));
    }
    
    cout<<ans<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("CARDS.IN","r",stdin);
    // freopen("CARDS.OUT","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}