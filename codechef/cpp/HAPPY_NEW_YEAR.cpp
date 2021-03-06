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

vector<int> pairs[maxN];

void init()
{
    for (int i = 1; i < maxN; i++)
    {
        for (int j = i + 1; j < maxN; j++)
        {
            pairs[i].push_back(i * j);
        }
    }
}

int counter(int n, int p)
{
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        for (int e : pairs[i])
        {
            if (e > n * i)
            {
                break;
            }
            else if (__gcd(e, p) == 1)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n, p;

    cin >> t;

    while (t--)
    {
        cin >> n >> p;
        cout << counter(n, p) << " ";
    }
    return 0;
}