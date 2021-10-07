You are given an undirected unweighted connected graph consisting of n vertices and m edges. It is guaranteed that there are no self-loops or multiple edges in 
the given graph. Your task is to find any spanning tree of this graph such that the maximum degree over all vertices is maximum possible. Recall that the degree 
of a vertex is the number of edges incident to it.

Input :-
The first line contains two integers n and m (2≤n≤2⋅105, n−1≤m≤min(2⋅105,n(n−1)2)) — the number of vertices and edges, respectively.
The following m lines denote edges: edge i is represented by a pair of integers vi, ui (1≤vi,ui≤n, ui≠vi), which are the indices of vertices connected by 
the edge. There are no loops or multiple edges in the given graph, i. e. for each pair (vi,ui) there are no other pairs (vi,ui) or (ui,vi) in the list of edges, 
and for each pair (vi,ui) the condition vi≠ui is satisfied.

Output :-
Print n−1 lines describing the edges of a spanning tree such that the maximum degree over all vertices is maximum possible. Make sure that the edges of the printed 
spanning tree form some subset of the input edges (order doesn't matter and edge (v,u) is considered the same as the edge (u,v)).
If there are multiple possible answers, print any of them.
   
	Examples :-
						   
inputCopy
5 5
1 2
2 3
3 5
4 3
1 5
outputCopy
3 5
2 1
3 2
3 4
inputCopy
4 6
1 2
1 3
1 4
2 3
2 4
3 4
outputCopy
4 1
1 2
1 3
						   
SOLUTION :-
												 

#include<bits/stdc++.h>

using namespace std;

const int mxn = 2e5 + 10;

vector<int> adj[mxn];
bool vis[mxn];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty())
    {
		int s = q.front();
		q.pop();
		for(auto i : adj[s])
		{
			if(vis[i]==false)
			{
			cout<< s << " " << i <<endl;
			q.push(i);
			vis[i] = true;
			}
		}
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int mxdeg = 0, indx = -1;
	for(int i = 1; i <= n; i++)
    {
		if(adj[i].size() > mxdeg)
		{
			mxdeg = adj[i].size();
			indx = i;
		}
	}
	bfs(indx);

	return 0;
}
