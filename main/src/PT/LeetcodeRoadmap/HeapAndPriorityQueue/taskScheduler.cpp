#include <iostream>
#include <vector>
#include <queue>

/*
    Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. 
    Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

    However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), 
    that is that there must be at least n units of time between any two same tasks.

    Return the least number of units of times that the CPU will take to finish all the given tasks.

    

    Example 1:

    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: 
    A -> B -> idle -> A -> B -> idle -> A -> B
    There is at least 2 units of time between any two same tasks.
*/

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> mp(26, 0);
        std::priority_queue<int> pq;
        std::queue<std::pair<int, int>> q;
        int tick = 0;
        
        for(auto i: tasks) {
           mp[i-'A']++;
        }
        
        for(auto i: mp) {
            if(i > 0) pq.push(i);
        }
        
        while(!pq.empty() || !q.empty()) {
            tick++;
            
            // move valid task from Q to PQ
            if(!q.empty() && q.front().second == tick) {
                pq.push(q.front().first);
                q.pop();
            }
            
            // do task and move it to Q with next valid time
            if(!pq.empty()){
                int i = pq.top();
                pq.pop();
                if(i-1 >= 1) {
                    q.push({i-1, tick+n+1});
                }                
            }

        }
        
        return tick;
    }
};

int main() {
    Solution s;
    std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    std::cout << s.leastInterval(tasks, n) << std::endl;

    return 0;
}