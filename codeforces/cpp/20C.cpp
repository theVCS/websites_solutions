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
    
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, a, b, w;

    cin >> n >> m;

    vector<pair<int,int>>arr[n + 1];

    REP(i, 0, m)
    {
        cin >> a >> b >> w;
        arr[a].push_back({b, w});
        arr[b].push_back({a, w});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n + 1, INT_MAX);

    pq.push({1, 0});
    dist[1] = 0;

    while (!pq.empty())
    {
        
    }
    

    return 0;
}