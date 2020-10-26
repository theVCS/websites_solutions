#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

bool isPallindrome(int n)
{
    int rev = 0, a = n;

    while (n)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    if (rev == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int larpall = 1, a = 100, b, db;

    while (a <= 999)
    {
        if (a % 11 == 0)
        {
            b = 999;
            db = 1;
        }
        else
        {
            b = 990;
            db = 11;
        }

        while (b >= a)
        {
            if (b * a <= larpall)
            {
                break;
            }

            if (isPallindrome(a * b))
            {
                larpall = a * b;
            }

            b -= db;
        }
        a++;
    }

    cout << larpall;

    return 0;
}