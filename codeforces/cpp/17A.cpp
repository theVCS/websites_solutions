#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, cnt = 0;
    vector<int> prime;

    cin >> n >> k;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            prime.push_back(i);
        }
    }

    for (int i :prime)
    {
        for (int j = 0; j < prime.size() - 1; j++)
        {
            if (prime[j] + prime[j + 1] + 1 > i)
            {
                break;
            }
            if (prime[j] + prime[j + 1] + 1 == i)
            {
                cnt++;
                break;
            }
        }
    }

    if (cnt >= k)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}