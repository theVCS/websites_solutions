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
    int num = 1;

    for (int i = 999; i > 100; i--)
    {
        for (int j = 999; j > 100; j--)
        {
            if (isPallindrome(i * j))
            {
                num = max(i * j , num);
            }
        }
    }
    cout<<num;

    return 0;
}