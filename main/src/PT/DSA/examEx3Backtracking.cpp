#include <iostream>

/*
    Let there be a checkered surface, represented by a square matrix of size n * m and 4 colors.
    Implement the necessary data structures and the following functionalities:
    - Color the map - the function proposes a way of coloring the surface, using the 4 colors so that the vertical and horizontal neighbors of a cell have different
    colors thab that of the cell.
    Choose an example of a surface of at least 3 * 3 elements and graph the surface after calling the Color map function.
    It is mandatory to comment on the algorithm and specify its complexity in terms of O(f(n)), comment on the chosen data structures, as well as justify their choice.
    It is mandatory to exemplify the call effect of the functions implemented on a chosen example.
*/

/*
    A common approach for coloring a checkered surface is to use a backtracking algorithm, which allows for the exploration of all possible colorings of the surface 
    while ensuring that the vertical and horizontal neighbors of a cell have different colors than that of the cell.

    One data structure that could be used to represent the checkered surface is a 2D array, where each cell in the array represents a square on the surface
    and contains the color of that square. Another data structure that could be used is an adjacency matrix, which keeps track of the edges between cells and can be used 
    to quickly determine if two cells are neighbors.

    The algorithm begins by initializing all cells in the surface to a default color, such as white. It then starts at the top-left corner of 
    the surface and begins exploring the possible colorings of each cell. For each cell, the algorithm checks the colors of its horizontal and vertical neighbors 
    and chooses a color that is different from those of its neighbors. If all four colors have been used and none of them are different from the colors of the neighbors, 
    the algorithm backtracks to the previous cell and tries a different color.

    The time complexity of this algorithm is O(n * m * 4^(n * m)), where n and m are the dimensions of the surface. This is because for each cell, 
    there are four possible colors to choose from and the algorithm may need to backtrack and try a different color if all four colors have been used.
*/

#define N 3
#define M 3

const char colors[4] = {'R', 'G', 'B', 'Y'};

char surface[N][M];
bool visited[N][M];

bool is_valid(int x, int y, char color) {
    // Check the horizontal and vertical neighbors of (x, y)
    if (x > 0 && surface[x - 1][y] == color) { 
        return false;
    }

    if (y > 0 && surface[x][y - 1] == color) { 
        return false;
    }

    if (x < N - 1 && surface[x + 1][y] == color) { 
        return false;
    }

    if (y < M - 1 && surface[x][y + 1] == color) { 
        return false;
    }
    
    return true;
}

bool color_map(int x, int y) {
    // All cells have been colored
    if (x == N && y == M) {
        return true;
    }

    // Move to next row
    if (y == M) { 
        return color_map(x + 1, 0); 
    }

    for (int c = 0; c < 4; c++) {
        if (is_valid(x, y, colors[c]) && !visited[x][y]) {
            surface[x][y] = colors[c];
            visited[x][y] = true;
            if (color_map(x, y + 1)) { 
                return true;
            }

            visited[x][y] = false;
        }
    }
    return false;
}

int main() {
    // Initialize the surface to all white
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            surface[i][j] = 'W';
        }
    }

    if (color_map(0, 0)) {
        // Print the colored surface
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%c ", surface[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.");
    }

    return 0;
}