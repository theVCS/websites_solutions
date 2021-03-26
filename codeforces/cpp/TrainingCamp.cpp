#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 19
#define INF 0x3f3f3f3f
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

map<string, int> mp;
int wt[maxN], intime[maxN];
vector<int> arr[maxN];
vector<int> lev[maxN];

void kahn(int n)
{
    queue<pii> q; // first is node and second is level

    REP(i, 1, n + 1)
    {
        if (intime[i] == 0)
            q.push({i, 0});
    }

    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        lev[level].push_back(node);
        // cout << node << " ";
        q.pop();

        for (int child : arr[node])
        {
            intime[child]--;

            if (intime[child] == 0)
            {
                q.push({child, level + 1});
            }
        }
    }
}

bool cmp(int a, int b)
{
    return wt[a] < wt[b];
}

void solve()
{
    mp.clear();

    int n, m, w;
    string s, s1, s2;

    cin >> n >> m;

    lev[0].clear();

    REP(i, 1, n + 1)
    {
        getline(cin, s);
        int j = s.size() - 1;

        while (s[j] != ' ')
        {
            j--;
        }
        w = stoi(s.substr(j + 1, s.size() - j - 2));
        s = s.substr(0, j);

        cout << s << w << endl;
        mp[s] = i;
        wt[i] = w;
        arr[i].clear();
        intime[i] = 0;
        lev[i].clear();
    }

    REP(i, 0, m)
    {
        getline(cin, s);
        int j = s.size() - 1;

        while (s[j] == '>')
        {
            j--;
        }

        s1 = s.substr(0, j - 3);
        s2 = s.substr(j + 2, s.size() - j - 2);

        int a = mp[s1], b = mp[s2];
        arr[a].push_back(b);
        intime[b]++;
    }

    kahn(n);
    ll res = 0;
    int k = 1;

    REP(i, 0, n)
    {
        sort(all(lev[i]), cmp);

        for (int child : lev[i])
        {
            res += (k * wt[child]);
            k++;
        }
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}