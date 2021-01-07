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

int init(int n)
{
    int a, b;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a = n / i;
            b = i;

            if (a >= 5 && b >= 5)
            {
                return a;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    int a = init(n), b;

    if (a == -1)
    {
        cout << -1;
        return 0;
    }

    b = n / a;

    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << vowels[(i + j) % vowels.size()];
        }
    }

    return 0;
}