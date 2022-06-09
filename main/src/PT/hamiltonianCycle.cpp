#include <iostream>
#include <cstdlib>

using namespace std;

#define V 5

bool isSafe(int v, bool graph[V][V], int* path, int pos){
    /* Check if this vertex is an adjacent
    vertex of the previously added vertex. */
    if (graph [path[pos - 1]][ v ] == 0){
        return false;
    }
 
    /* Check if the vertex has already been included.
    This step can be optimized by creating
    an array of size V */
    for (int i = 0; i < pos; i++){
        if (path[i] == v){
            return false;
        }
    }
 
    return true;
}

bool hamCycleUtil(bool graph[V][V], int* path, int pos){
    //if all the vertices are included in the path
    if (pos == V)
    {
        if (graph[path[pos-1]][path[0]] == 1)
        {
            return true;
        }else{
            return false;
        }
        
    }

    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added
        // to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, pos + 1) == true){
                return true;
            }
 
            /* If adding vertex v doesn't lead to a solution,
            then remove it */
            path[pos] = -1;
        }
    }

    return false;
    
}

void printSolution(int* path){
    cout << "Solution exists:";

    for (int i = 0; i < V; i++)
    {
        cout << path[i] << " ";
    }

    cout << path[0] << " " << endl;
    
}

bool hamCycle(bool graph[V][V]){
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    /* Let us put vertex 0 as the first vertex in the path.
    If there is a Hamiltonian Cycle, then the path can be
    started from any point of the cycle as the graph is undirected */
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false )
    {
        cout << "\nSolution does not exist";
        return false;
    }
 
    printSolution(path);
    return true;
}


int main(){
    /* Let us create the following graph
        (0)--(1)--(2)
        | / \ |
        | / \ |
        | / \ |
        (3)-------(4) */
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    // print solution
    hamCycle(graph1);

    /* Let us create the following graph
    (0)--(1)--(2)
    | / \ |
    | / \ |
    | / \ |
    (3) (4) */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};

    // print solution
    hamCycle(graph2);

    return 0;
}