#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// 1 k u ---> a[k] = u;
// 2 a b ---> sum = arr[a, b];
ll n, m;
ll arr[maxN], last[maxN], sum, ans[maxN];
bool use[maxN];

int nq, nu;

struct query
{
    int l, r, t, lblk, rblk, index;
} q[maxN];

struct update
{
    int k;
    ll new_u, prev_u;
} u[maxN];

void add(int index)
{
    use[index] = true;
    sum += arr[index];
}

void remove(int index)
{
    use[index] = false;
    sum -= arr[index];
}

void reflect_update(int index, ll value)
{
    if (!use[index])
    {
        arr[index] = value;
        return;
    }
    remove(index);
    arr[index] = value;
    add(index);
}

void do_update(int index)
{
    reflect_update(u[index].k, u[index].new_u);
}

void undo(int index)
{
    reflect_update(u[index].k, u[index].prev_u);
}

bool cmp(query a, query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.rblk < b.rblk) || (a.lblk == b.lblk && a.rblk == b.rblk && a.t & 1 ? a.t < b.t : a.t > b.t);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;

    // scanf("%d %d", &n, &m);
    cin >> n >> m;

    const ll blk = max(1, (int)pow(n * 1.0, 2.0 / 3.0));

    REP(i, 1, n + 1)
    {
        // scanf("%lld", arr + i);
        cin >> arr[i];
        last[i] = arr[i];
    }

    REP(i, 0, m)
    {
        // scanf("%lld %lld %lld", &a, &b, &c);
        cin >> a;
        cin >> b >> c;

        if (a == 1)
        {
            nu++;
            u[nu].k = b;
            u[nu].new_u = c;
            u[nu].prev_u = last[b];
            last[b] = c;
        }
        else
        {
            nq++;
            q[nq].l = b;
            q[nq].r = c;
            q[nq].index = nq;
            q[nq].lblk = b / blk;
            q[nq].rblk = c / blk;
            q[nq].t = nu;
        }
    }

    sort(q + 1, q + 1 + nq, cmp);

    for (int i = 1, L = 1, R = 0, T = 0; i < nq + 1; i++)
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

        ans[q[i].index] = sum;
    }

    REP(i, 1, nq + 1)
    printf("%lld\n", ans[i]);

    return 0;
}