#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
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
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int blk = 2100;
const int arrSize = 100001;
const int querSize = 100001;
const int freSize = 200001;

struct Query
{
    int l, r, t, index;
} q[querSize];

struct Update
{
    int index, new_y, prev_y;
} u[querSize];

bool cmp(Query const &a, Query const &b)
{
    if (a.t / blk != b.t / blk)
        return a.t < b.t;
    if (a.l / blk != b.l / blk)
        return a.l < b.l;
    return a.r < b.r;
}

int arr[arrSize];  // array which contains main data
int last[arrSize]; // last element present in the vector
bool use[arrSize]; // used in update
int fre[freSize]; // use to keep track of no of elements

// extra variables
int ff[arrSize];
map<int,int>mp;

template <class TYPE>
class MOWithUpdate
{
    int n, m;
    int nq, nu;
    TYPE res;
    vector<TYPE> ans;

public:
    MOWithUpdate(int N, int M)
    {
        n = N, m = M;
        nq = nu = res = 0;
        ans.resize(M + 1);
    }

    void addQuery(int a, int b)
    {
        nq++;
        q[nq].l = a;
        q[nq].r = b;
        q[nq].index = nq;
        q[nq].t = nu;
    }

    void addUpdate(int index, TYPE val)
    {
        nu++;
        u[nu].index = index;
        u[nu].new_y = val;
        u[nu].prev_y = last[index];
        last[index] = val;
    }

    void add(int index)
    {
        ll ele = arr[index];
        use[index] = true;

        --ff[fre[ele]];
        ++fre[ele];
        ++ff[fre[ele]];
    }

    void remove(int index)
    {
        ll ele = arr[index];
        use[index] = false;

        --ff[fre[ele]];
        --fre[ele];
        ++ff[fre[ele]];
    }

    void reflect_update(int index, int ele)
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

    int getAns()
    {
        REP(i, 1, 600)
        if (ff[i] == 0)
            return i;
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

            ans[q[i].index] = getAns();
        }
    }

    void showAns()
    {
        REP(i,1,nq)cout<<ans[i]<<endl;
    }

    void preprocess()
    {
        int timer = 0;

        for(auto &e: mp)
            e.second = ++timer;

        REP(i,1,n)
        arr[i]=mp[arr[i]];

        REP(i,1,nu)
        u[i].new_y = mp[u[i].new_y],
        u[i].prev_y = mp[u[i].prev_y];
    }
};


void solve()
{
    int n, m;
    cin>>n>>m;

    MOWithUpdate<int>mo(n,m);

    REP(i,1,n)
    {
        cin>>arr[i];
        last[i]=arr[i];
        mp[arr[i]];
    }

    REP(i,1,m)
    {
        int type,a,b;
        cin>>type>>a>>b;

        if(type==1)
        {
            mo.addQuery(a,b);
        }
        else
        {
            mp[b];
            mo.addUpdate(a,b);
        }
    }

    mo.preprocess();
    mo.processQueries();
    mo.showAns();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("inputD.txt","r",stdin);
    // freopen("a.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}