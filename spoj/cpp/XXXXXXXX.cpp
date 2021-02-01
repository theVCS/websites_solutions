#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int N = 5e4 + 10;
const int Q = 1e5 + 10;
int blk;

struct Query
{
    int l, r, t, ind, lb, rb;
} q[Q];

struct Update
{
    //A[x] = new_y;
    int x, new_y, prev_y;
} u[Q];

bool cmp(Query a, Query b)
{
    return (a.lb < b.lb) || (a.lb == b.lb && a.rb < b.rb) || (a.lb == b.lb && a.rb == b.rb && a.t < b.t);
}

int A[N], last[N], nu, nq, compressed_value, cnt[N + Q];
ll ans[Q], curr_ans, rev[N + Q];
bool use[N];
map<int, int> fre;

void add(int index)
{
    use[index] = true;

    if (++cnt[A[index]] == 1)
    {
        curr_ans += rev[A[index]] * 1LL;
    }
}

void remove(int index)
{
    use[index] = false;

    if (--cnt[A[index]] == 0)
    {
        curr_ans -= rev[A[index]] * 1LL;
    }
}

void reflect_update(int index, int value)
{
    if (!use[index])
    {
        A[index] = value;
        return;
    }
    remove(index);
    A[index] = value;
    add(index);
}

void do_update(int index)
{
    reflect_update(u[index].x, u[index].new_y);
}

void undo(int index)
{
    reflect_update(u[index].x, u[index].prev_y);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    // cin >> n;
    scanf("%d", &n);

    blk = max(1, (int)pow(n, 2.0 / 3));

    REP(i, 1, n + 1)
    {
        // cin >> A[i];
        scanf("%d", A + i);
        last[i] = A[i];
        fre[A[i]];
    }

    int m;

    // cin >> m;
    scanf("%d", &m);

    char c[2];
    int l, r;

    // getting data
    REP(i, 0, m)
    {
        // cin >> c >> l >> r;
        scanf("%s %d %d", c, &l, &r);

        if (c[0] == 'U')
        {
            nu++;
            u[nu].x = l;
            u[nu].new_y = r;
            u[nu].prev_y = last[l];
            last[l] = r;
            fre[r];
        }
        else
        {
            nq++;
            q[nq].l = l;
            q[nq].r = r;
            q[nq].t = nu;
            q[nq].ind = nq;
            q[nq].lb = l / blk;
            q[nq].rb = r / blk;
        }
    }

    for (auto &it : fre)
    {
        it.second = ++compressed_value;
        rev[compressed_value] = it.first;
    }
    for (int i = 1; i < n + 1; i++)
    {
        A[i] = fre[A[i]];
    }
    for (int i = 1; i < nu + 1; i++)
    {
        u[i].prev_y = fre[u[i].prev_y];
        u[i].new_y = fre[u[i].new_y];
    }

    sort(q + 1, q + 1 + nq, cmp);

    for (int i = 1, T = 0, L = 1, R = 0; i < nq + 1; i++)
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

        ans[q[i].ind] = curr_ans;
    }

    for (int i = 1; i < nq + 1; i++)
    {
        printf("%lld\n", ans[i]);
    }

    return 0;
}