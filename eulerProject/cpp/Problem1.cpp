#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0, n;

    n = 999 / 3;
    sum += 3 * (n * (n + 1)) / 2;

    n = 999 / 5;
    sum += 5 * (n * (n + 1)) / 2;

    n = 999 / 15;
    sum -= 15 * (n * (n + 1)) / 2;

    cout << sum;

    return 0;
}