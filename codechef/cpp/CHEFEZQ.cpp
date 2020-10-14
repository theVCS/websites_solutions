#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, n;
    long long ans, k, num, messages_left;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        messages_left = 0;
        ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> num;
            messages_left += num;
            ans++;
            messages_left -= k;
            if (messages_left < 0)
            {
                break;
            }
        }

        if (messages_left < 0)
        {
            cout << ans << endl;
        }
        else if (messages_left == 0)
        {
            cout << ans + 1 << endl;
        }
        else
        {
            cout << ans + (messages_left / k) + 1 << endl;
        }
    }

    return 0;
}