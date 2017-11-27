305. Number of Islands II

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

class Solution {
public:
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        // for every new island
        // give a new id, islands++
        // check neighbors
        //  if no island around, done;
        //  else: insert their root in a set, update the root
        //        islands - set.size
        
        vector<int> result;
        int num_island = 0;
        vector<int> root(m*n, -1);
        
        vector<vector<int>> board(m, vector<int>(n, 0));
        
        int dir[8] = {0, 1, 0, -1, 1, 0, -1, 0};
        
        int level = 0;
        
        for (auto p : positions) {
            
            int i = p.first, j = p.second, cur = i*n + j;
            root[cur] = cur;
            num_island++;
            
            for (int d = 0; d < 8; d += 2) {
                int x = i + dir[d], y = j + dir[d+1], next = x*n+y;
                if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && root[next] != -1) {
                                  
                    int val = root[next];
                    while (root[val] != val)  {
                        root[val] = root[root[val]];
                        val = root[val];      
                    }
                    if (val != cur) {
                        
                        root[val] = cur;
                        num_island--;
                    }
                }
            }

            result.push_back(num_island);

        }
        
        return result;
        
    }
    
};