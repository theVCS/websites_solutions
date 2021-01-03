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

    int n;

    cin >> n;

    int arr[n], sum1 = 0, sum2 = 0, ptf = 0, ptb = n - 1, curr;

    REP(i, 0, n)
    cin >> arr[i];

    while (true)
    {
        if (n == 1)
        {
            sum1 += arr[ptf];
            break;
        }
        else if (n == 2)
        {
            sum1 += max(arr[ptf], arr[ptb]);
            sum2 += min(arr[ptf], arr[ptb]);
            break;
        }
        
        if (arr[ptf] > arr[ptb])
        {
            sum1 += arr[ptf];
            ptf++;
        }
        else
        {
            sum1 += arr[ptb];
            ptb--;
        }

        if (arr[ptf] > arr[ptb])
        {
            sum2 += arr[ptf];
            ptf++;
        }
        else
        {
            sum2 += arr[ptb];
            ptb--;
        }

        n-=2;
    }

    cout << sum1 << " " << sum2;

    return 0;
}