#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int sumDigit(int n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int primeSum(int a)
{
    int sum = 0, k;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            k = sumDigit(i);
            while (a % i == 0)
            {
                sum += k;
                a /= i;
            }
        }
    }

    if (a > 1)
    {
        sum += sumDigit(a);
    }
    
    return sum;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (sumDigit(n) == primeSum(n))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}