/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 * 
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */

#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 200000);
    int t = rnd.next(1, n);
    int m = rnd.next(1, 1000);

    cout << n << " " << m << endl;

    vector<int> p(n);

    /* setup parents for vertices 1..n-1 */
    for (int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

    /* shuffle vertices 1..n-1 */
    vector<int> perm(n);
    for (int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());

    /* put edges considering shuffled vertices */
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    /* shuffle edges */
    shuffle(edges.begin(), edges.end());

    for (int i = 0; i + 1 < n; i++)
        printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);

    for (int i = 0; i < m; i++)
    {
        set<int> s;

        for (int j = 0; j < 200; j++)
        {
            s.insert(rnd.next(1, n));
        }

        int sz = 0;
        printf("%d ", s.size());
        for (int e : s)
        {
            sz++;
            if (sz < s.size())
                printf("%d ", e);
            else
                printf("%d", e);
        }
        printf("\n");
    }

    return 0;
}
