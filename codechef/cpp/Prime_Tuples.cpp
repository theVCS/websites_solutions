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

bool isPrime[maxN];
int res[maxN];

void init()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i] == false)
        {
            for (int j = i * i; j < maxN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    res[1] = res[2] = res[3] = res[4] = 0;

    for (int i = 5; i < maxN; i++)
    {
        if (isPrime[i - 2] || i % 2 == 0 || isPrime[i])
        {
            res[i] = res[i - 1];
        }
        else
        {
            res[i] = res[i - 1] + 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t;

    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        cout << res[n] << endl;
    }

    return 0;
}