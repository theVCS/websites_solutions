#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> primes;
bool isPrime[maxN];

void init()
{
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

    for (int i = 2; i < maxN; i++)
    {
        if (!isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int n, one = 0, two = 0, dum, ind = 0;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> dum;

        if (dum == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    if (two)
    {
        cout << 2 << " ";
        two--;
    }

    if (one)
    {
        cout << 1 << " ";
        one--;
    }

    while (two--)
    {
        cout << 2 << " ";
    }

    while (one--)
    {
        cout << 1 << " ";
    }
    

    return 0;
}