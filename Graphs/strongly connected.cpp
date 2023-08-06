#include <bits/stdc++.h>

void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,stack <int> &st,int node){
	vis[node]=true;

	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfs(adj,vis,st,nbr);
		}
	}
	st.push(node);
}

void revDfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis,int node){
	vis[node]=true;

	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			revDfs(adj,vis,nbr);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

		adj[u].push_back(v);
	}

	//topological sort
	stack <int> st;
	unordered_map<int,bool> vis;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(adj,vis,st,i);
		}
	}

	//create transpose graph
	unordered_map<int,list<int>> transpose;
	for(int i=0;i<v;i++){
		vis[i]=false;
		for(auto j:adj[i]){
			transpose[j].push_back(i);
		}
	}

	//dfs acc to topological sort
	int count=0;
	while(!st.empty()){
		int top=st.top();
		st.pop();
		if(!vis[top]){
			count++;
			revDfs(transpose,vis,top);
		}
	}
	return count;
}