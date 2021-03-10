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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct cor
{
    int a1, a2, a3, a4;
};

int position[5];
int dis[71];
int nodes[71];

bool isValid(int x, cor e)
{
    if (x > 70)
        return false;

    int cnt = 0;

    if (e.a2 == x)
        cnt++;
    if (e.a3 == x)
        cnt++;
    if (e.a2 == x)
        cnt++;

    return (cnt == 0);
}

void bfs1()
{
    cor e;
    queue<cor> q;
    e.a1 = 1, e.a2 = 2, e.a3 = 3, e.a4 = 4;
    q.push(e);

    while (!q.empty())
    {
        cor ele = q.front();
        q.pop();

        int _a1 = ele.a2 + (ele.a2 - ele.a1);

        if (isValid(_a1, ele))
        {
            if (dis[_a1] > dis[ele.a1] + 1)
            {
                dis[_a1] = dis[ele.a1] + 1;
                cor _e = ele;
                _e.a1 = _a1;
                q.push(_e);
                nodes[_a1] = 1;
            }
        }

        _a1 = ele.a3 + (ele.a3 - ele.a1);

        if (isValid(_a1, ele))
        {
            if (dis[_a1] > dis[ele.a1] + 1)
            {
                dis[_a1] = dis[ele.a1] + 1;
                cor _e = ele;
                _e.a1 = _a1;
                q.push(_e);
                nodes[_a1] = 1;
            }
        }

        _a1 = ele.a4 + (ele.a4 - ele.a1);

        if (isValid(_a1, ele))
        {
            if (dis[_a1] > dis[ele.a1] + 1)
            {
                dis[_a1] = dis[ele.a1] + 1;
                cor _e = ele;
                _e.a1 = _a1;
                q.push(_e);
                nodes[_a1] = 1;
            }
        }

        int _a2 = ele.a3 + (ele.a3 - ele.a2);

        if (isValid(_a2, ele))
        {
            if (dis[_a2] > dis[ele.a2] + 1)
            {
                dis[_a2] = dis[ele.a2] + 1;
                cor _e = ele;
                _e.a2 = _a2;
                q.push(_e);
                nodes[_a2] = 1;
            }
        }

        _a2 = ele.a4 + (ele.a4 - ele.a2);

        if (isValid(_a2, ele))
        {
            if (dis[_a2] > dis[ele.a2] + 1)
            {
                dis[_a2] = dis[ele.a2] + 1;
                cor _e = ele;
                _e.a2 = _a2;
                q.push(_e);
                nodes[_a2] = 1;
            }
        }

        int _a3 = ele.a4 + (ele.a4 - ele.a3);

        if (isValid(_a3, ele))
        {
            if (dis[_a3] > dis[ele.a3] + 1)
            {
                dis[_a3] = dis[ele.a3] + 1;
                cor _e = ele;
                _e.a3 = _a3;
                q.push(_e);
                nodes[_a3] = 1;
            }
        }
    }
}

void solve()
{
    cin >> position[1] >> position[2] >> position[3] >> position[4];
    REP(i,0,71)dis[i] = INF;
    dis[1] = dis[2] = dis[3] = dis[4] = 0;

    bfs1();

    // REP(i, 1, 15)
    cout << dis[position[1]] << " ";
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