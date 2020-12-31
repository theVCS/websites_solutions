#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 49
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int cc;

void dfs(int node)
{
    vis[node] = true;
    cc++;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

void dfs1(int node)
{
    vis[node] = true;

    cout << node << " ";

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs1(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    vector<int> three, two, one;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cc = 0;
            dfs(i);

            if (cc > 3)
            {
                cout << -1;
                return 0;
            }
            else if (cc == 3)
            {
                three.push_back(i);
            }
            else if (cc == 2)
            {
                two.push_back(i);
            }
            else
            {
                one.push_back(i);
            }
        }
    }

    // for(int e: three)
    // {
    //     cout << e << " ";
    // }cout <<endl;

    // for(int e: two)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    
    // for(int e: one)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    if (one.size() < two.size())
    {
        cout << -1;
        return 0;
    }
    

    REP(i, 0, 50)
    {
        vis[i] = false;
    }

    for (int a : two)
    {
        int b = one.back();
        one.pop_back();

        arr[a].push_back(b);
        arr[b].push_back(a);
        // cout << a << " <=---=> " << b << endl;
    }

    for (int i = 0; i < one.size(); i += 3)
    {
        int k = one[i];
        int l = one[i + 1];
        int m = one[i + 2];

        arr[k].push_back(l);
        arr[l].push_back(k);

        arr[k].push_back(m);
        arr[m].push_back(k);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs1(i);
            cout << endl;
        }
    }

    return 0;
}