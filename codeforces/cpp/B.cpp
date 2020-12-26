#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100002
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool sieve[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1;
    }
    else if (n == 2)
    {
        cout << 1 << endl;
        cout << 1 << " " << 1;
    }
    else
    {
        cout << 2 << endl;

        for (int i = 2; i * i <= n + 2; i++)
        {
            if (!sieve[i])
            {
                for (int j = i * i; j < n + 2; j += i)
                {
                    sieve[j] = true;
                }
            }
        }

        for (int i = 2; i < n + 2; i++)
        {
            if (sieve[i])
            {
                cout << 2 << " ";
            }
            else
            {
                cout << 1 << " ";
            }
        }
    }

    return 0;
}