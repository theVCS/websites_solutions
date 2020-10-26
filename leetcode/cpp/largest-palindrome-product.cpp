#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

ll getLargest(ll n)
{
    ll num = 0;

    while (n--)
    {
        num = num * 10 + 9;
    }
    return num;
}

ll getMinimum(ll n)
{
    ll num = 1;

    while (n--)
    {
        num = num * 10;
    }
    return num;
}

bool isPallindrome(ll n)
{
    ll rev = 0, a = n;

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

    ll n, largest, smallest, a, b, larpall = 0, d;

    cin >> n;

    largest = getLargest(n);
    smallest = max(1 * 1LL, getMinimum(n - 1));

    a = smallest;
    b = largest;

    while (a <= largest)
    {
        if (n % 2 == 0)
        {
            if (a % 11 == 0)
            {
                d = 1;
            }
            else
            {
                b = (largest / 11) * 11;
                d = 11;
            }
        }
        else
        {
            d = 1;
        }

        while (b >= a)
        {
            if (b * a <= larpall)
            {
                break;
            }
            
            if (isPallindrome(b * a))
            {
                larpall = a * b;
            }

            b -= d;
        }
        a++;
    }
    cout << larpall;

    return 0;
}