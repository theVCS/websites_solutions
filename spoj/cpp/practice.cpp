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

int blk;
const int N = 5e4 + 10;
const int Q = 1e5 + 10;
int A[N], last[N], rev[N + Q], cnt[N + Q];
bool use[N];

struct query
{
    int index, l, r, t, lb, rb;
} q[Q];

struct Update
{
    int x, new_y, prev_y;
} u[Q];

bool cmp(query a, query b)
{
    return (a.lb < b.lb) || (a.lb == b.lb && a.rb < b.rb) || (a.lb == b.lb && a.rb == b.rb && a.t < b.t);
}

ll ans[Q], curr_ans;
int nq, nu, compressed_val;

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

void reflect_update(int index, int y)
{
    if (!use[index])
    {
        A[index] = y;
        return;
    }
    remove(index);
    A[index] = y;
    add(index);
}

void do_update(int index)
{
    reflect_update(u[index].x, u[index].new_y);
}

void undo_update(int index)
{
    reflect_update(u[index].x, u[index].prev_y);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    scanf("%d", &n);

    blk = pow(n, 2.0 / 3.0);

    map<int, int> mp;

    REP(i, 1, n + 1)
    {
        scanf("%d", A + i);
        last[i] = A[i];
        mp[A[i]];
    }

    int m;

    scanf("%d", &m);

    for (int i = 1; i < m + 1; i++)
    {
        char s[2];
        int x, y;

        scanf("%s %d %d", s, &x, &y);

        if (s[0] == 'Q')
        {
            nq++;
            q[nq] = {nq, x, y, nu, x / blk, y / blk};
        }
        else
        {
            u[++nu] = {x, y, last[x]};
            last[x] = y;
            mp[y];
        }
    }

    for (auto &it : mp)
    {
        it.second = ++compressed_val;
        rev[compressed_val] = it.first;
    }
    for (int i = 1; i <= n; i++)
    {
        A[i] = mp[A[i]];
    }
    for (int i = 1; i <= nu; i++)
    {
        u[i].new_y = mp[u[i].new_y];
        u[i].prev_y = mp[u[i].prev_y];
    }

    sort(q + 1, q + nq + 1, cmp);

    for (int i = 1, T = 0, L = 1, R = 0; i < nq + 1; i++)
    {
        while (T < q[i].t)
            do_update(++T);
        while (T > q[i].t)
            undo_update(T--);
        while (R < q[i].r)
            add(++R);
        while (L > q[i].l)
            add(--L);
        while (R > q[i].r)
            remove(R--);
        while (L < q[i].l)
            remove(L++);
        ans[q[i].index] = curr_ans;
    }

    for (int i = 1; i < nq + 1; i++)
    {
        printf("%lld\n", ans[i]);
    }

    return 0;
}