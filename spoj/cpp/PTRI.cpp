#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<bool> sieve(maxN);
vector<int> arr(maxN);

void init()
{
    int pos = 0;
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!sieve[i])
        {
            arr[i] = ++pos;
            for (int j = i * i; j < maxN; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    for (int i = 10001; i < maxN; i += 2)
    {
        if (!sieve[i])
        {
            arr[i] = ++pos;
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
    ll n, pos, row, col;

    cin >> t;

    while (t--)
    {
        cin >> n;

        pos = arr[n];

        if (pos)
        {
            row = ceil((sqrt(8 * pos + 1) - 1) / 2);
            col = pos - (row * (row - 1)) / 2;
            cout << row << " " << col << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}