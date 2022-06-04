#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//function to add an edge to vertex
void addEdge(vector<int> adj[], int src, int dest){
    adj[src].push_back(dest);
}

//function to print adjacent list of a graph
void displayGraph(vector<int> adj[], int v){
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout<<endl;
        
    }
    
}

//function to get transpose of a graph
void transposeGraph(vector<int> adj[], vector<int> transpose[], int v){
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            addEdge(transpose, adj[i][j], i);
        }
        
    }
    
}

int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);

// Finding transpose of graph represented
    // by adjacency list adj[]
    vector<int> transpose[v];
    transposeGraph(adj, transpose, v);
 
    // displaying adjacency list of transpose
    // graph i.e. b
    displayGraph(transpose, v);

    return 0;
}