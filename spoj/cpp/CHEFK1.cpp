#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    ll N, M, res;

    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        if (M < (N - 1) || M > ((N * (1 + N)) / 2))
        {
            res = -1;
        }
        else
        {
            if (N == 1)
            {
                if (M == 0)
                {
                    res = 0;
                }
                else
                {
                    res = 1;
                }
            }
            else if (N == 2)
            {
                if (M == 1)
                {
                    res = 1;
                }
                else if (M == 2)
                {
                    res = 2;
                }
                else
                {
                    res = 2;
                }
            }
            else
            {
                if (M <= 1 + N)
                {
                    res = 2;
                }
                else if (M <= (N * 2))
                {
                    res = 3;
                }
                else
                {
                    res = ((2 * (M - N) + N - 1) / N) + 1;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
