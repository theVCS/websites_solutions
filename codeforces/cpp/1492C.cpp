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
#define all(x) (x).begin(), (x).end()

vector<int> arr[26];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, mIndex;
    string s, t;

    cin >> n >> m;

    cin >> s >> t;

    REP(i, 0, n)
    {
        arr[s[i] - 'a'].push_back(i + 1);
    }

    int res = 0;
    mIndex = arr[t[m - 1] - 'a'].back();

    for (int i = m - 2; i >= 0; i--)
    {
        int index;

        if (i == 0)
        {
            index = arr[t[i] - 'a'].front();
            res = max(mIndex - index, res);
            break;
        }

        // cout << mIndex << endl;
        index = upper_bound(all(arr[t[i] - 'a']), mIndex) - arr[t[i] - 'a'].begin();
        int ele = arr[t[i] - 'a'][index - 1];
        arr[t[i] - 'a'].erase(arr[t[i] - 'a'].begin() + index - 1);
        res = max(mIndex - ele, res);
        mIndex = ele;
    }

    cout << res;

    return 0;
}