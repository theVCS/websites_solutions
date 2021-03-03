#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000501
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool prime[maxN];
int primeR[maxN];

void init()
{
    prime[0] = prime[1] = true;

    for (int i = 2; i * i <= maxN; i++)
    {
        for (int j = i * i; j < maxN; j += i)
        {
            prime[j] = true;
        }
    }

    int last = maxN;

    for (int i = maxN - 1; i >= 0; i--)
    {
        primeR[i] = last;

        if (prime[i] == false)
            last = i;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    int t, l,r;

    cin >> t;

    while (t--)
    {
        cin >> l >> r;
        cout << primeR[r] << endl;
    }

    return 0;
}