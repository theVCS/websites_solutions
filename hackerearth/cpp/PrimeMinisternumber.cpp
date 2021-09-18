#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000001
bool isPrime[max];
bool pm[max];

int digit_sum(int _number)
{
    int sum = 0;

    while (_number)
    {
        sum += _number % 10;
        _number /= 10;
    }
    return sum;
}

void sieve()
{
    int digitSum;
    isPrime[0] = isPrime[1] = true;

    for (int i = 2; i * i <= max; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j < max; j += i)
            {
                isPrime[j] = true;
            }
        }
    }

    for (int i = 2; i < max; i++)
    {
        digitSum = digit_sum(i);
        if (!isPrime[i] && !isPrime[digitSum])
        {
            pm[i] = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int a, b;

    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (pm[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}