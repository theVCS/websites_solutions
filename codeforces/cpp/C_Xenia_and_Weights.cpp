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

map<pii, vector<pii>> graph;
vector<int> weights;

void graphBuilder(int m)
{
    pii a, b;

    // making level first
    for (int w : weights)
    {
        graph[{w, w}].push_back({0, 0});
        graph[{0, 0}].push_back({w, w});
    }

    for (int step = 2; step <= m; step++)
    {
        for (auto e : graph)
        {
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    int m;

    cin >> s >> m;

    for (int i = 0; i < 10; i++)
    {
        if (s[i] == '1')
        {
            weights.push_back(i + 1);
        }
    }

    return 0;
}