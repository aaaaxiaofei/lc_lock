317. Shortest Distance from All Buildings

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.



class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        // put all building locations in vector<pair<int, int>>
        // from each building, BFS the matrix, update the distance in matrix copy
        // add current matrix to a sum matrix
        // after finish BFS of all building, find the min sum
        
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<pair<int, int>> building;
        vector<vector<int>> dist_grid(grid.size(), vector<int>(grid[0].size(), 0));
        
        for (int i = 0;i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) building.push_back(make_pair(i, j));
            }
        }
          
        
        for (auto b : building) {
            bfs(grid, b.first, b.second, dist_grid);
        }
        
        bool canBuild = false;
        int dist = INT_MIN;
        for (int i = 0; i < dist_grid.size(); i++) {
            for (int j = 0; j < dist_grid[i].size(); j++) {
                if (dist_grid[i][j] < 0) {
                    dist = max(dist, dist_grid[i][j]);
                    canBuild = true;
                }
            }
            // printf("\n");
        }
        
        return canBuild ? -dist : -1;
        
    }
    
    void bfs(vector<vector<int>> grid, int i, int j, vector<vector<int>>& dist_grid) {
        
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1},{0,-1}};
        queue<int> q;
        
        q.push(i); q.push(j);
        int dist = -1;
        
        while (!q.empty()) {
            
            int n = q.size();
            
            while (n > 0) {
            
                int i = q.front(); q.pop();
                int j = q.front(); q.pop();
                for (auto d : dir) {
                    int x = i + d.first, y = j + d.second;
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && grid[x][y] == 0) {
                        grid[x][y] = dist;
                        q.push(x);
                        q.push(y);

                    }
                }
                
                n -= 2;
            }
            
            dist--;
        }
        
        for (int i = 0; i < dist_grid.size(); i++) {
            for (int j = 0; j < dist_grid[i].size(); j++) {
                if (grid[i][j] < 0 && dist_grid[i][j] <= 0) {
                    dist_grid[i][j] += grid[i][j];
                }
                else
                    dist_grid[i][j] = 1;
            }
        } 

    }

};


======== Faster Solution ===========
I also tested the other three C++ solutions posted so far, they took 340-1812 ms. I think mine is faster because I don't use a fresh "visited" for each BFS. Instead, I walk only onto the cells that were reachable from all previous buildings. From the first building I only walk onto cells where grid is 0, and make them -1. From the second building I only walk onto cells where grid is -1, and I make them -2. And so on.

int shortestDistance(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    auto total = grid;
    int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) {
                mindist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (q.size()) {
                    auto ij = q.front();
                    q.pop();
                    for (int d=0; d<4; ++d) {
                        int i = ij.first + delta[d];
                        int j = ij.second + delta[d+1];
                        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                            grid[i][j]--;
                            dist[i][j] = dist[ij.first][ij.second] + 1;
                            total[i][j] += dist[i][j] - 1;
                            q.emplace(i, j);
                            if (mindist < 0 || mindist > total[i][j])
                                mindist = total[i][j];
                        }
                    }
                }
                walk--;
            }
        }
    }
    return mindist;
}