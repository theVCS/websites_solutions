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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool isSupUg[maxN];
vector<int> s;

void sieve()
{
    isSupUg[1] = true;

    for (int e : s)
    {
        for (int i = e; i < maxN; i += e)
        {
            isSupUg[i] = true;
        }
    }

    for (int i = 1; i < maxN; i++)
    {
        if (!isSupUg[i])
        {
            for (int j = i; j < maxN; j += i)
            {
                isSupUg[j] = false;
            }
        }
    }
}

void init(ll x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            s.push_back(i);

            while (x % i == 0)
            {
                x /= i;
            }
        }
    }

    if (x > 1)
    {
        s.push_back(x);
    }
    sieve();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x, dum;

    cin >> x;
    init(x);

    int n;
    cin >> n;

    REP(i, 0, n)
    {
        cin >> dum;

        if (isSupUg[dum])
        {
            cout << dum << " ";
        }
    }

    return 0;
}