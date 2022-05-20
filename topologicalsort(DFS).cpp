#include<bits/stdc++.h>
void toposort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj)
{
	visited[node]=true;
	for(auto i:adj[node])
	{
		if(not visited[i])
			toposort(i,visited,s,adj);
	}
	s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
	unordered_map<int,list<int>>adj;
	vector<bool>visited(v,false);
	stack<int>s;
	for(int i=0;i<e;i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	for(int i=0;i<v;i++)
	{
		if(not visited[i])
			toposort(i,visited,s,adj);
	}
	vector<int>ans;
	while(not s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}
