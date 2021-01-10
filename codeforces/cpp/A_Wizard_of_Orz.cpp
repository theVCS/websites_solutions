#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
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

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        queue<int> q;

        for (int i = 0; i < 10; i++)
        {
            q.push(i);
        }

        int k;

        if (n == 1)
        {
            cout << "9";
        }
        else if (n == 2)
        {
            cout << "98";
        }
        else if (n >= 3)
        {
            cout << "989";
        }

        if (n > 3)
        {
            n -= 3;

            while (n--)
            {
                k = q.front();
                q.pop();
                cout << k;
                q.push(k);
            }
        }
        cout << endl;
    }

    return 0;
}