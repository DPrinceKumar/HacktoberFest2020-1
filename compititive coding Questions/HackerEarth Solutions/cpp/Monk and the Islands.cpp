#include <bits/stdc++.h> 
using namespace std; 
void add_edge(vector<int> adj[], int src, int dest){ 
	adj[src].push_back(dest); 
	adj[dest].push_back(src); 
} 
bool BFS(vector<int> adj[], int src, int dest, int v, 
		int pred[], int dist[]) { 
	list<int> queue; 
	bool visited[v];
	for (int i = 0; i < v; i++) { 
		visited[i] = false; 
		dist[i] = INT_MAX; 
		pred[i] = -1; 
	} 
	visited[src] = true; 
	dist[src] = 0; 
	queue.push_back(src);
	while (!queue.empty()) { 
		int u = queue.front(); 
		queue.pop_front(); 
		for (int i = 0; i < adj[u].size(); i++) { 
			if (visited[adj[u][i]] == false) { 
				visited[adj[u][i]] = true; 
				dist[adj[u][i]] = dist[u] + 1; 
				pred[adj[u][i]] = u; 
				queue.push_back(adj[u][i]); 
				if (adj[u][i] == dest) 
					return true; 
			} 
		} 
	} 

	return false; 
}
void printShortestDistance(vector<int> adj[], int s, 
						int dest, int v) { 
	int pred[v], dist[v]; 
	if (BFS(adj, s, dest, v, pred, dist) == false) { 
		cout << -1; 
		return; 
	} 
	vector<int> path; 
	int crawl = dest; 
	path.push_back(crawl); 
	while (pred[crawl] != -1) { 
		path.push_back(pred[crawl]); 
		crawl = pred[crawl]; 
	} 
	cout << dist[dest]<<endl; 
}
int main() 
{ 
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n];
        while(m--){
            int x,y;
            cin>>x>>y;
            add_edge(adj,x-1,y-1);
        }
        int source=0,dest=n-1;
        printShortestDistance(adj,source,dest,n);
    }
	return 0; 
} 
