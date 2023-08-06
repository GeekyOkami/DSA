#include <unordered_map>
#include <list>

bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,int node){
  visited[node]=true;
  dfsVisited[node]=true;

  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool detect=dfs(adj,visited,dfsVisited,neighbour);
      if(detect){
        return true;
      }
    }
    else if(dfsVisited[neighbour]){
        return true;
    }
  }
  dfsVisited[node]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      bool cycle=dfs(adj,visited,dfsVisited,i);
      if(cycle){
        return true;
      }
    }
  }

  return false;
}