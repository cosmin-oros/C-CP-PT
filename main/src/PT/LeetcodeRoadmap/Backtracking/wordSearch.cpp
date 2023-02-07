#include <iostream>
#include <vector>

/*
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
    The same letter cell may not be used more than once.

    

    Example 1:


    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
*/

class Solution {
public:
    int r;
    int c;
    int neighbor[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    std::vector<std::vector<char>> grid;
    
    bool dfs(std::string &s, int curr, int x, int y)
    {
        if(curr == s.length()-1) {
            return true;
        }
        
        char t = grid[x][y];
        grid[x][y] = '#';
        bool res = false;
        int px,py;

        for(int i = 0; i < 4; i++)
        {
            px = x + neighbor[i][0];
            py = y + neighbor[i][1];
            
            if(px >= 0 && px < r && py >= 0 && py < c && grid[px][py] == s[curr+1])
            {                
                res |= dfs(s,curr+1,px,py);
                if(res) {
                    break;
                }
            }
        }
        
        grid[x][y] = t;
        return res;
    }
    
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
    
        r = board.size();
        c = board[0].size();
        
        if(word.length() > r*c) {
            return false;
        }
        
        grid = board;        
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    char* word = "ABCCED";
    Solution s;
    
    std::cout << s.exist(board, word) << std::endl;

    return 0;
}