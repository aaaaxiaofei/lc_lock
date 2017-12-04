361. Bomb Enemy

Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int m = grid.size(), n = grid[0].size();
        
        
        vector<vector<int>> m1(m, vector<int>(n, 0)), m2(m, vector<int>(n, 0)),
                            m3(m, vector<int>(n, 0)), m4(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            int carry1 = 0, carry2 = 0;     
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    m1[i][j] = grid[i][j] == 'W' ? 0 : m1[i][j-1] + carry1;
                    m2[i][n-1-j] = grid[i][n-1-j] == 'W' ? 0 : m2[i][n-j] + carry2;
                }
                carry1 = grid[i][j] == 'E';
                carry2 = grid[i][n-1-j] == 'E';
            }
        }
        
        int result = 0;
        
        for (int j = 0; j < n; j++) {
            int carry1 = 0, carry2 = 0;     
            for (int i = 0; i < m; i++) {
                if (i > 0) {
                    m3[i][j] = grid[i][j] == 'W' ? 0 : m3[i-1][j] + carry1;
                    m4[m-1-i][j] = grid[m-1-i][j] == 'W' ? 0 : m4[m-i][j] + carry2;
                }
                carry1 = grid[i][j] == 'E';
                carry2 = grid[m-i-1][j] == 'E';
            }
        }
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    result = max(result, m1[i][j] + m2[i][j] + m3[i][j] + m4[i][j]);
                }
            }
        }
        
        return result;
        
        
           
    }
    
};
