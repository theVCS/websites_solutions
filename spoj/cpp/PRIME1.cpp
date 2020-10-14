#include <iostream>
#include <cmath>
using namespace std;

bool prime_checker(long long a)
{
    for (long long i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int t;
    long long m, n;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (long long i = m; i < n + 1; i++)
        {
            if (prime_checker(i))
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }

    return 0;
}