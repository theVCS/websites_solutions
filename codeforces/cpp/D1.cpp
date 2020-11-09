/*
https://codeforces.com/contest/160/problem/D
*/

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

int n;
int arr[100001];
struct edge
{
    int a;
    int b;
    int w;
    string s;
};

struct dumedge
{
    int a;
    int b;
};
// list<edge> obj[1000001];
edge obj[1000001];
dumedge dum[1000001];

bool comp(edge a, edge b)
{
    if (a.w < b.w)
    {
        return true;
    }
    return false;
}

int find(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    else
    {
        return arr[a] = find(arr[a]);
    }
}

void merge(int a, int b)
{
    if (arr[a] > arr[b])
    {
        swap(a, b);
    }

    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> obj[i].a >> obj[i].b >> obj[i].w;
        dum[i].a = obj[i].a;
        dum[i].b = obj[i].b;
        obj[i].s = "none";
    }

    sort(obj, obj + m, comp);

    REP(i, 1, n + 1)
    {
        arr[i] = -1;
    }

    REP(i, 0, m)
    {
        int a = find(obj[i].a);
        int b = find(obj[i].b);

        if (a != b)
        {
            obj[i].s = "any";
            merge(a, b);
        }
        else
        {
            int j = i - 1;
            while (j > -1 && obj[j].w == obj[i].w)
            {
                obj[i].s = "at least one";
                obj[j].s = "at least one";
                j--;
            }
        }
    }

    REP(i, 0, m)
    {
        REP(j, 0, m)
        {
            if (dum[i].a == obj[j].a && dum[i].b == obj[j].b)
            {
                cout << obj[j].s << endl;
                break;
            }
        }
    }

    return 0;
}