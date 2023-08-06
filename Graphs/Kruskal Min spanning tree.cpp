#include <bits/stdc++.h> 
bool cmp(vector<int> &a,vector<int> &b){
	return a[2]<b[2];
}

int findParent(vector<int> &parent,int node){
	if(parent[node]==node){
		return node;
	}
	return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
	u=findParent(parent,u);
	v=findParent(parent,v);

	if(rank[u]<rank[v]){
		parent[u]=v;
	}
	else if(rank[v]<rank[u]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}
}

void initialize(vector<int> &parent,vector<int> &rank,int n){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		rank[i]=0;
	}
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(),graph.end(),cmp);

	vector<int> parent(n+1);
	vector<int> rank(n+1);
	initialize(parent,rank,n);
	int minWt=0;

	for(int i=0;i<graph.size();i++){
		int u=findParent(parent,graph[i][0]);
		int v=findParent(parent,graph[i][1]);

		if(u!=v){
			minWt+=graph[i][2];
			unionSet(u,v,parent,rank);
		}
	}

	return minWt;
}