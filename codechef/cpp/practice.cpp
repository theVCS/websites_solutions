#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<pair<int,int>> nodes(n);
    for(int i=0;i<n;i++){
        nodes[i]=mp(adj[i].size(), i);
    }
    sort(nodes.begin(), nodes.end(), greater<pair<int,int>>());
    if(nodes[0].first!=n-1){
        cout<<"NO\n";
        return;
    }
    vector<vector<int>> adjtree(n);
    vector<bool> vis(n);
    vector<int> depth(n);
    vector<int> par(n);
    par[nodes[0].second]=-1;
    depth[nodes[0].second]=1;
    vis[nodes[0].second]=1;
    for(int i=1;i<n;i++){
        int mxdepth=-1;
        int node = nodes[i].second;
        vis[node]=1;
        int ans=-1;
        for(int j=0;j<adj[node].size();j++){
            if(vis[adj[node][j]]){
                if(depth[adj[node][j]]>mxdepth){
                    ans=adj[node][j];
                    mxdepth=depth[adj[node][j]];
                }
            }
        }
        if(ans==-1){
            cout<<"NO\n";
            return;
        }
        adjtree[ans].pb(node);
        adjtree[node].pb(ans);
        par[node]=ans;
        depth[node]=depth[ans]+1;
    } 
    int M=0;
    vector<int> curr;
    vector<vector<int>> newgraph(n);
    fill(vis.begin(), vis.end(), 0);
    curr.reserve(n);
    vis[nodes[0].second]=1;
    curr.pb(nodes[0].second);
    while(curr.size()!=0){
        bool flag=0;
        for(const auto& node : adjtree[curr.back()]){
            if(!vis[node]){
                curr.pb(node);
                vis[node]=1;
                flag=1;
                break;
            }
        }
        if(!flag){
            for(int i=0;i<curr.size()-1;i++){
                newgraph[curr.back()].pb(curr[i]);
                newgraph[curr[i]].pb(curr.back());
                ++M;
                if(M>m){
                    cout<<"NO\n";
                    return;
                }
            }
            curr.pop_back();
        }
    }
    for(int i=0;i<n;i++){
        if(adj[i].size()!=newgraph[i].size()){
            cout<<"NO\n";
            return;
        }
        sort(adj[i].begin(), adj[i].end());
        sort(newgraph[i].begin(), newgraph[i].end());
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]!=newgraph[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
        for(int j=0;j<newgraph[i].size();j++){
            cout<<newgraph[i][j]<<" ";
        }
        cout<<"\n\n";
    }
    */
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        cout<<par[i]+1<<" ";
    }
    cout<<"\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}