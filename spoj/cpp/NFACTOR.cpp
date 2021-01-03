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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sieve[maxN];
int col[maxN];
int cnt[11];
int final[maxN][11];
vector<int> arr(11, 0);

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j < maxN; j += i)
            {
                sieve[j] = i;
            }
        }
    }
}

int disDiv(int a)
{
    set<int> s;

    while (sieve[a])
    {
        s.insert(sieve[a]);
        a = a / sieve[a];
    }

    return s.size();
}

void init2()
{
    init();

    col[1] = 0;

    int s;

    REP(i, 2, maxN)
    {
        s = disDiv(i);
        col[i] = s;
    }

    REP(i, 1, maxN)
    {
        cnt[col[i]]++;

        REP(j, 0, 11)
        {
            final[i][j] = cnt[j];
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init2();

    int t, a, b, n;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> n;
        cout << final[b][n] - final[a][n] + (final[a][n] - final[a - 1][n]) << endl;
    }

    return 0;
}