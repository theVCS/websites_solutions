#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T, N, K, X, Y, d;
    bool is_break = true;
    cin >> T;

    while (T--)
    {
        cin >> N >> K >> X >> Y;
        d = (X + K) % N;

        if (X == Y)
        {
            cout << "YES" << endl;
            continue;
        }

        while (d != X)
        {
            if (d == Y)
            {
                cout << "YES" << endl;
                is_break = false;
                break;
            }

            d = (d + K) % N;
        }

        if (is_break)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}