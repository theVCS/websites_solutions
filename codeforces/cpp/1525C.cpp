#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 300001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int arr[maxN];
int res[maxN];
vector<pii> l[2], r[2];

pii bs(vector<pii> &vec, int ele)
{
    int start = 0, end = vec.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (vec[mid].first > ele && (mid == 0 || vec[mid - 1].first <= ele))
        {
            return {vec[mid].second, mid};
        }
        else if (vec[mid].first <= ele)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return {-1, -1};
}

int bsi(vector<pii> &vec, int ele)
{
    int start = 0, end = vec.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (vec[mid].first < ele && (mid == vec.size() - 1 || vec[mid + 1].first > ele))
        {
            return mid;
        }
        else if (vec[mid].first >= ele)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

void solve()
{
    l[0].clear(), l[1].clear();
    r[0].clear(), r[1].clear();

    int n, m;
    char c;

    cin >> n >> m;

    REP(i, 1, n)
    cin >> arr[i];

    REP(i, 1, n)
    {
        cin >> c;

        if (c == 'L')
            l[arr[i] % 2].push_back({arr[i], i});
        else
            r[arr[i] % 2].push_back({arr[i], i});

        res[i] = -1;
    }

    sort(all(l[0]));
    sort(all(l[1]));
    sort(all(r[0]));
    sort(all(r[1]));

    // checking for left and right
    int i = r[0].size() - 1;

    if (l[0].size())
    {
        i = bsi(r[0], l[0].back().first);

        while (i >= 0)
        {
            if (l[0].size() == 0)
                break;

            pii index1 = bs(l[0], r[0][i].first);
            int index2 = r[0][i].second;

            if (index1.first == -1)
            {
                i--;
                continue;
            }

            l[0].erase(l[0].begin() + index1.second);

            int mid = (arr[index1.first] + arr[index2]) / 2;

            res[index1.first] = abs(arr[index1.first] - mid);
            res[index2] = abs(arr[index2] - mid);

            r[0].erase(r[0].begin() + i);
            i--;
        }
    }

    // checking for left and right
    i = r[1].size() - 1;
    if (l[1].size())
    {
        i = bsi(r[1], l[1].back().first);

        while (i >= 0)
        {
            if (l[1].size() == 0)
                break;

            pii index1 = bs(l[1], r[1][i].first);
            int index2 = r[1][i].second;

            if (index1.first == -1)
            {
                i--;
                continue;
            }

            l[1].erase(l[1].begin() + index1.second);

            int mid = (arr[index1.first] + arr[index2]) / 2;

            res[index1.first] = abs(arr[index1.first] - mid);
            res[index2] = abs(arr[index2] - mid);

            r[1].erase(r[1].begin() + i);
            i--;
        }
    }

    // moving in same direction
    while (l[0].size() > 1)
    {
        int index1 = l[0][0].second;
        int index2 = l[0][1].second;

        int ele1 = l[0][0].first;
        int ele2 = l[0][1].first;

        int ans = (ele2 - ele1) / 2;
        res[index1] = ele1 + ans;
        res[index2] = ele2 - ans;

        l[0].erase(l[0].begin());
        l[0].erase(l[0].begin());
    }

    while (l[1].size() > 1)
    {
        int index1 = l[1][0].second;
        int index2 = l[1][1].second;

        int ele1 = l[1][0].first;
        int ele2 = l[1][1].first;

        int ans = (ele2 - ele1) / 2;
        res[index1] = ele1 + ans;
        res[index2] = ele2 - ans;

        l[1].erase(l[1].begin());
        l[1].erase(l[1].begin());
    }

    i = r[0].size() - 1;
    while (r[0].size() > 1)
    {
        int index1 = r[0][i].second;
        int index2 = r[0][i - 1].second;

        int ele1 = r[0][i].first;
        int ele2 = r[0][i - 1].first;

        int ans = m + (ele2 - ele1) / 2;
        res[index1] = (m - ele1) + (m - ans);
        res[index2] = ans - ele2;

        r[0].pop_back();
        r[0].pop_back();
        i -= 2;
    }

    i = r[1].size() - 1;

    while (r[1].size() > 1)
    {
        int index1 = r[1][i].second;
        int index2 = r[1][i - 1].second;

        int ele1 = r[1][i].first;
        int ele2 = r[1][i - 1].first;

        int ans = m + (ele2 - ele1) / 2;
        res[index1] = (m - ele1) + (m - ans);
        res[index2] = ans - ele2;

        r[1].pop_back();
        r[1].pop_back();
        i -= 2;
    }

    for (int i = 0, j = r[0].size() - 1; i < l[0].size() && j > -1; i++, j--)
    {
        int index1 = l[0][i].second;
        int index2 = r[0][j].second;

        int ele1 = l[0][i].first;
        int ele2 = r[0][j].first;

        int ans = m - ((ele1 + ele2) / 2);

        res[index1] = ele1 + ans;
        res[index2] = (m - ele2) + (m - ans);
    }

    for (int i = 0, j = r[1].size() - 1; i < l[1].size() && j > -1; i++, j--)
    {
        int index1 = l[1][i].second;
        int index2 = r[1][j].second;

        int ele1 = l[1][i].first;
        int ele2 = r[1][j].first;

        int ans = m - ((ele1 + ele2) / 2);

        res[index1] = ele1 + ans;
        res[index2] = (m - ele2) + (m - ans);
    }

    REP(i, 1, n)
    cout << res[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}