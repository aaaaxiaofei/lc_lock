490. The Maze

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze wont exceed 100.

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        if (maze.size() == 0 || maze[0].size() == 0) return false;
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));  
        return dfs(maze, visited, start, destination, -1);
    }
    
    bool dfs(vector<vector<int>>& maze, vector<vector<int>>& visited, vector<int> start, vector<int>& destination, int dir) {

        int x = start[0], y = start[1];
        visited[x][y] = 1;
        if (x == destination[0] && y == destination[1]) return true;
        
        bool result = false;      
        vector<int> direction = {1, -1};        
                   
        for (auto d : direction) {
            
            
            // Search in x direction
            if (dir != 0) { 
                int i = x, j = y;
                while (((d == -1 && i > 0) || (d == 1 && i < maze.size()-1)) && maze[i+d][j] == 0) 
                    i += d;
                if (visited[i][j] == 0) 
                    result |= dfs(maze, visited, vector<int>{i, j}, destination, 0);
            }
            
            // Search in y direction
            if (dir != 1) {  
                int i = x, j = y;
                while (((d == -1 && j > 0) || (d == 1 && j < maze[0].size()-1)) && maze[i][j+d] == 0) 
                    j += d;
                if (visited[i][j] == 0) 
                    result |= dfs(maze, visited, vector<int>{i, j}, destination, 1);
            }
        }
        
        return result;
        
    }


};