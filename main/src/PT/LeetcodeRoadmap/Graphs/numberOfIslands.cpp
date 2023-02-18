#include <iostream>
#include <vector>
#include <queue>

/*
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    

    Example 1:

    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1
*/

class Solution {
public:
      void bfs(int row, int col, std::vector<std::vector<int>> &visited, std::vector<std::vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        std::queue<std::pair<int,int>> que;
        que.push({row, col});
        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                    int nrow = row+dx[i];
                    int ncol = col +dy[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        que.push({nrow, ncol});
                        visited[nrow][ncol]=1;
                    }
                }
            }
        }
    
  public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]  && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
        {"1", "1"},
        {"1", "0"}
    };
    Solution s;

    std::cout << s.numIslands(grid);

    return 0;
}