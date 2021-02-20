// #include <bits/stdc++.h>
// //#include <boost/multiprecision/cpp_int.hpp>
// //using namespace boost::multiprecision;
// using namespace std;
// #define ll long long int
// //#define bint cpp_int
// #define pii pair<int, int>
// #define mod 1000000007
// #define REP(i, a, b) for (int i = a; i < b; i++)
// #define maxN 30001
// #define all(x) (x).begin(), (x).end()
// //int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// //int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// //int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// //int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// int arr[maxN];
// multiset<int> segTree[maxN * 4];

// void build(int si, int ss, int se)
// {
//     if (ss == se)
//     {
//         segTree[si].insert(arr[ss]);
//     }
//     else
//     {
//         int mid = (ss + se) / 2;
//         build(2 * si, ss, mid);
//         build(2 * si + 1, mid + 1, se);

//         for (int e : segTree[2 * si])
//             segTree[si].insert(e);
//         for (int e : segTree[2 * si + 1])
//             segTree[si].insert(e);
//     }
// }

// int query(int si, int ss, int se, int qs, int qe, int val)
// {
//     if (ss > qe || se < qs)
//     {
//         return 0;
//     }
//     if (qs <= ss && qe >= se)
//     {
//         return distance(segTree[si].upper_bound(val), segTree[si].end());
//     }

//     int mid = (ss + se) / 2;
//     return (query(2 * si, ss, mid, qs, qe, val) + query(2 * si + 1, mid + 1, se, qs, qe, val));
// }

// void update(int si, int ss, int se, int qi, int newVal, int oldVal)
// {
//     if (ss == se)
//     {
//         segTree[si].erase(segTree[si].find(oldVal));
//         segTree[si].insert(newVal);
//         return;
//     }
//     int mid = (ss + se) / 2;

//     if (qi <= mid)
//         update(2 * si, ss, mid, qi, newVal, oldVal);
//     else
//         update(2 * si + 1, mid + 1, se, qi, newVal, oldVal);

//     segTree[si].erase(segTree[si].find(oldVal));
//     segTree[si].insert(newVal);
// }

// int main(int argc, char const *argv[])
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     // cout.tie(NULL);

//     int n, m, flag, a, b, c;

//     scanf("%d", &n);

//     REP(i, 1, n + 1)
//     {
//         scanf("%d", arr + i);
//     }

//     build(1, 1, n);

//     scanf("%d", &m);

//     while (m--)
//     {
//         scanf("%d", &flag);

//         if (flag == 0)
//         {
//             scanf("%d %d", &a, &b);
//             update(1, 1, n, a, b, arr[a]);
//             arr[a] = b;
//         }
//         else
//         {
//             scanf("%d %d %d", &a, &b, &c);
//             printf("%d\n", query(1, 1, n, a, b, c));
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 30001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN], fre[10001];
int segTree[40004];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = fre[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;

    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = fre[qi];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, newN = INT_MIN, m, flag, a, b, c;

    scanf("%d", &n);

    REP(i, 1, n + 1)
    {
        scanf("%d", arr + i);
        newN = max(newN, arr[i]);
        fre[arr[i]]++;
    }

    build(1, 1, newN);

    scanf("%d", &m);

    while (m--)
    {
        scanf("%d", &flag);

        if (flag == 0)
        {
            // convert arr[a] = b;
            scanf("%d %d", &a, &b);

            fre[arr[a]]--;
            update(1, 1, n, arr[a]);

            fre[b]++;
            update(1, 1, n, b);
        }
        else
        {
            // find number of elments greater than c in range [a,b]
            scanf("%d %d %d", &a, &b, &c);
        }
    }

    return 0;
}