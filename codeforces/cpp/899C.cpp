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

    ll n, sum, a = 0, b = 0;

    cin >> n;

    sum = (n * (n + 1)) / 4;

    vector<int> g1;
    vector<int> g2;

    for (int i = n; i >= 1; i--)
    {
        if (sum - i >= 0)
        {
            g1.push_back(i);
            sum -= i;
            a += i;
        }
        else
        {
            b += i;
            g2.push_back(i);
        }
    }

    cout << abs(a - b) << endl;
    cout << g2.size() << " ";

    for (int child : g2)
    {
        cout << child << " ";
    }

    return 0;
}