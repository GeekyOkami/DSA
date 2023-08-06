#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n+1);
    vector<int> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }

    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        for(int v=1;v<=n;v++){
            if(key[v]<mini && mst[v]==false){
                u=v;
                mini=key[v];
            }
        }

        mst[u]=true;

        //adj list
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(w<key[v] && mst[v]==false){
                key[v]=w;
                parent[v]=u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}