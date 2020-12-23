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

int binExp(int a, int pow, int m = 1000)
{
    int res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * a) % m;
            pow--;
        }
        a = (a * a) % m;
        pow /= 2;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, k;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cout << int(pow(10, k * log10(n) - floor(k * log10(n)) + 2)) << "..." << binExp(n % 1000, k) << endl;
    }

    return 0;
}