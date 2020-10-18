#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000001
bool isPrime[max];
int up[max];

int digit_sum(int _digit)
{
    int sum = 0;
    while (_digit)
    {
        sum += _digit % 10;
        _digit /= 10;
    }
    return sum;
}

void sieve()
{
    int digitSum, total_up = 0;
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

        if (!isPrime[digitSum] && !isPrime[i])
        {
            total_up++;
        }

        up[i] = total_up;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t, l, r;
    cin >> t;

    while (t--)
    {
        cin >> l >> r;
        cout << up[r] - up[l - 1] << endl;
    }

    return 0;
}