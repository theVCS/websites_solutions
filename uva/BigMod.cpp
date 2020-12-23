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

int binexp(int a, int pow, int m = mod)
{
    int res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            pow--;
            res = (res * a) % m;
        }
        pow /= 2;
        a = (a * a) % m;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int b, p, m;

    while (cin >> b && cin >> p && cin >> m)
    {
        cout << binexp(b % m, p, m) << endl;
    }

    return 0;
}