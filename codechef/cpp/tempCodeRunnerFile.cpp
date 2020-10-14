#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int T, N, K, X, Y, len;
    cin >> T;

    while (T--)
    {
        cin >> N >> K >> X >> Y;

        if (K == 0)
        {
            if (X == Y)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }
        else if (K == 1)
        {
            cout << "YES";
        }
        else
        {

            len = (X >= Y ? (N - X) + (Y + 1) : Y - X);
            if (len % K)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}