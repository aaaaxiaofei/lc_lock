286. Walls and Gates

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    dfs(rooms, i, j, 0);
                }
            }
        }
    }
    
    void dfs(vector<vector<int>>& rooms, int i, int j, int dist) {

        if (dist > 0 && (rooms[i][j] <= 0 || rooms[i][j] <= dist)) return;
            
        rooms[i][j] = dist;
        
        int dir[] = {1, 0, -1, 0, 0, 1, 0, -1};      
        for (int d = 0; d < 8; d += 2) {
            int x = i + dir[d], y = j + dir[d+1];
            if (x >= 0 && x < rooms.size() && y >= 0 && y < rooms[x].size()) {
                dfs(rooms, x, y, dist+1);
            }
        }
    }
};