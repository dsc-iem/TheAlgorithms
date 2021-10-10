#include<bits/stdc++.h>
using namespace std;

class Graph {
	// A function used by DFS
public:
    void DFSUtil(int v);
	map<int, bool> visited;
	map<int, list<int>> adj;
	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints DFS traversal of the complete graph
	void connected();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::DFSUtil(int v)
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (visited[*i]==false)
			DFSUtil(*i);
}
void Graph::connected()
{
    for(int v=0;v<adj.size();v++)
    {
        if(!visited[v])
        {
            DFSUtil(v);
            cout<<endl;
        }
    }
}
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

	cout << "Following is the no of components \n";
    g.connected();
	return 0;
}
