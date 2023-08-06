#include <bits/stdc++.h>

void dfs(int i,int parent,int &timer,vector<int> &low,vector<int> &disc,unordered_map<int,bool> &vis,
        vector<vector<int>> &result,unordered_map<int,list<int>> &adj){

            vis[i]=true;
            low[i]=disc[i]=timer++;

            for(auto nbr:adj[i]){
                if(nbr==parent){
                    continue;
                }

                if(!vis[nbr]){
                    dfs(nbr,i,timer,low,disc,vis,result,adj);
                    low[i]=min(low[i],low[nbr]);
                    //check edge is bridge
                    if(low[nbr]>disc[i]){
                        vector<int> ans;
                        ans.push_back(i);
                        ans.push_back(nbr);
                        result.push_back(ans);
                    }
                }

                else{
                    low[i]=min(low[i],disc[nbr]);
                }
            }
    }

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int> low(v);
    vector<int> disc(v);
    int parent=-1;
    unordered_map<int,bool> vis;
    vector<vector<int>> result;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,low,disc,vis,result,adj);
        }
    }

    return result;

}