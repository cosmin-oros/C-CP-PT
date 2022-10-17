#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

#define N 4

/*
    Let there be N workers and N jobs. 
    Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. 
    It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent 
    in such a way that the total cost of the assignment is minimized.
*/

// state space tree node
struct Node{
    Node* parent;
    // cost for ancestors nodes
    int pathCost;
    // least promising cost
    int cost;
    int workerID;
    int jobID;
    bool assigned[N];
};

// func to alloc new search tree node
Node* newNode(int x, int y, bool assigned[], Node* parent){
    Node* node = new Node();

    for (int i = 0; i < N; i++)
    {
        node->assigned[i] = assigned[i];
    }
    node->assigned[y] = true;

    node->parent = parent;
    node->workerID = x;
    node->jobID = y;

    return node;
    
}

// func to calculate least promising cost
int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[]){
    int cost = 0;
    bool available[N] = {true};

    for (int i = x+1; i < N; i++)
    {
        int min = INT_MAX, minIndex = -1;

        // each job
        for (int j = 0; j < N; j++)
        {
            if (!assigned[j] && available[j] && costMatrix[i][j] < min)
            {
                minIndex = j;
                min = costMatrix[i][j];
            }
            
        }

        cost += min;
        available[minIndex] = false;
        
    }

    return cost;
    
}

// Comparison object to be used to order the heap
struct comp{
    bool operator()(const Node* lhs, const Node* rhs) const{
        return lhs->cost > rhs->cost;
    }
};

void printAssignments(Node* min){
    if (min->parent == NULL)
    {
        return;
    }

    printAssignments(min->parent);
    
    cout << "Assign worker " << char(min->workerID + 'A') << " to job " << min->jobID << endl; 
    
}

// finds min cost using branch and bound
int findMinCost(int costMatrix[N][N]){
    priority_queue<Node*, vector<Node*>, comp> pq;

    bool assigned[N] = {false};
    Node* root = newNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;
  
    // Add dummy node to list of live nodes;
    pq.push(root);
  
    // Finds a live node with least cost,
    // add its childrens to list of live nodes and
    // finally deletes it from the list.
    while (!pq.empty())
    {
      // Find a live node with least estimated cost
      Node* min = pq.top();
  
      // The found node is deleted from the list of
      // live nodes
      pq.pop();
  
      // i stores next worker
      int i = min->workerID + 1;
  
      // if all workers are assigned a job
      if (i == N)
      {
          printAssignments(min);
          return min->cost;
      }
  
      // do for each job
      for (int j = 0; j < N; j++)
      {
        // If unassigned
        if (!min->assigned[j])
        {
            // create a new tree node
            Node* child = newNode(i, j, min->assigned, min);
    
            // cost for ancestors nodes including current node
            child->pathCost = min->pathCost + costMatrix[i][j];
    
            // calculate its lower bound
            child->cost = child->pathCost +
                calculateCost(costMatrix, i, j, child->assigned);
    
            // Add child to list of live nodes;
            pq.push(child);
        }
      }
    }
}

int main(){
    int costMatrix[N][N] =
    {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    cout << "Optimal cost is: " << findMinCost(costMatrix) << endl; 
    
    return 0;
}