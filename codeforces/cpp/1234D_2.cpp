#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;
int nq, nu;
int fre[26], ans;
bool use[maxN];
int res[maxN];

struct query
{
    int l, r, lblk, rblk, t, index;
} Q[maxN];

struct update
{
    int index;
    char prevC, newC;
} U[maxN];

bool cmp(query a, query b)
{
    return (a.lblk < b.lblk) || (a.lblk == b.lblk && a.rblk < b.rblk) || (a.lblk == b.lblk && a.rblk == b.rblk && a.t < b.t);
}

void add(int index)
{
    int i = s[index] - 'a';
    use[index] = true;

    if (++fre[i] == 1)
        ans++;
}

void remove(int index)
{
    int i = s[index] - 'a';
    use[index] = false;

    if (--fre[i] == 0)
        ans--;
}

void refUpdate(int index, char c)
{
    if (!use[index])
    {
        s[index] = c;
        return;
    }
    remove(index);
    s[index] = c;
    add(index);
}

void do_update(int index)
{
    refUpdate(U[index].index, U[index].newC);
}

void undo(int index)
{
    refUpdate(U[index].index, U[index].prevC);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, code, a, b;
    char c;
    string last;

    cin >> s;

    n = s.size();

    const int blk = pow(n, 2.0 / 3.0);

    s.insert(0, "0");
    last = s;

    cin >> m;

    while (m--)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> a >> c;
            nu++;

            U[nu].index = a;
            U[nu].newC = c;
            U[nu].prevC = last[a];
            last[a] = c;
        }
        else
        {
            cin >> a >> b;
            nq++;

            Q[nq].l = a;
            Q[nq].r = b;
            Q[nq].t = nu;
            Q[nq].lblk = a / blk;
            Q[nq].rblk = b / blk;
            Q[nq].index = nq;
        }
    }

    sort(Q + 1, Q + 1 + nq, cmp);

    for (int i = 1, L = 1, R = 0, T = 0; i <= nq; i++)
    {
        while (T < Q[i].t)
            do_update(++T);
        while (T > Q[i].t)
            undo(T--);
        while (R < Q[i].r)
            add(++R);
        while (L > Q[i].l)
            add(--L);
        while (R > Q[i].r)
            remove(R--);
        while (L < Q[i].l)
            remove(L++);

        res[Q[i].index] = ans;
    }

    REP(i, 1, nq + 1)
    cout << res[i] << endl;

    return 0;
}