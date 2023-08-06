#include <bits/stdc++.h>>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
				q.push(i);
				parent[i]=front;
				visited[i]=true;
			}
		}
	}

	vector<int> ans;
	int curr_node=t;
	ans.push_back(curr_node);
	while(curr_node!=s){
		curr_node=parent[curr_node];
		ans.push_back(curr_node);
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
