#include <iostream>
#include <list>

using namespace std;

/*
    Given a tree represented as an undirected graph. Count the number of nodes at a given level l. It may be assumed that vertex 0 is the root of the tree.

      0         Level 0
    /   \ 
    1     2      Level 1
   / |\    |
   3 4 5   6      Level 2
*/

class Graph{
    int V;  // nr of vertices

    list<int>* adj;

public:
    // constructor
    Graph(int V);

    // count of nodes at level l from source s
    int BFS(int s, int l);

    void addEdge(int v, int w);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int Graph::BFS(int s, int l){
    bool* visited = new bool[V];
    int* level = new int[V];
 
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        level[i] = 0;
    }

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);
    level[s] = 0;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for (auto i = adj[s].begin();
                  i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                level[*i] = level[s] + 1;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < V; i++){
        if (level[i] == l){
            count++;   
        }
    }

    return count; 
}

int main(){ 
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
 
    int level = 2;
 
    cout << g.BFS(0, level);

    return 0;
}