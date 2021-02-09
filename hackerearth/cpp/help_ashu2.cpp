#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100051
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN], last[maxN];
bool use[maxN];
int even, odd, nu, nq, ans[maxN];

struct query
{
    int l, r, lb, rb, index, t, c;
} q[maxN];

struct update
{
    int l, new_r, old_r;
} u[maxN];

void add(int index)
{
    use[index] = true;
    even += (arr[index] + 1) % 2;
    odd += arr[index] % 2;
}

void remove(int index)
{
    use[index] = false;
    even -= (arr[index] + 1) % 2;
    odd -= arr[index] % 2;
}

void reflect_upadate(int index, ll value)
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
    reflect_upadate(u[index].l, u[index].new_r);
}

void undo(int index)
{
    reflect_upadate(u[index].l, u[index].old_r);
}

bool cmp(query a, query b)
{
    return (a.lb < b.lb) || (a.lb == b.lb && a.rb < b.rb) || (a.lb == b.lb && a.rb == b.rb && a.t < b.t);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c;
    ll l, r;

    cin >> n;

    int blk = max(1, (int)pow(n, 2.0 / 3.0));

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        last[i] = arr[i];
    }

    cin >> m;

    while (m--)
    {
        cin >> c >> l >> r;

        if (c == 0)
        {
            nu++;
            u[nu].l = l;
            u[nu].new_r = r;
            u[nu].old_r = last[l];
            last[l] = r;
        }
        else
        {
            nq++;
            q[nq].c = c;
            q[nq].t = nu;
            q[nq].index = nq;
            q[nq].l = l;
            q[nq].lb = l / blk;
            q[nq].r = r;
            q[nq].rb = r / blk;
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

        if (q[i].c == 1)
        {
            ans[q[i].index] = even;
        }
        else
        {
            ans[q[i].index] = odd;
        }
    }

    REP(i, 1, nq + 1)
    cout << ans[i] << endl;

    return 0;
}