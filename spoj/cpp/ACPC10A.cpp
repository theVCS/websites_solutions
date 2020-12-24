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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;

    cin >> a >> b >> c;

    while (a || b || c)
    {
        if(a == b && b == c)
        {
            cout << "GP " << a << endl;
        }
        else if ((2 * b) == (a + c))
        {
            cout << "AP " << c + (b - a) << endl;
        }
        else
        {
            cout << "GP " << c * b / a << endl;
        }

        cin >> a >> b >> c;
    }

    return 0;
}