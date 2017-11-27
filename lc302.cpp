302. Smallest Rectangle Enclosing Black Pixels 

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        if (image.size() == 0 || image[0].size() == 0) return 0;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
        int m = image.size(), n = image[0].size();
        
        vector<vector<int>> visit(m, vector<int>(n, 0));
        
        dfs(image, visit, x, y, min_x, max_x, min_y, max_y);
        
        return (max_x - min_x + 1) * (max_y - min_y + 1);
        
    }
    
    void dfs(vector<vector<char>>& image, vector<vector<int>>& visit, int x, int y, int& min_x, int& max_x, int& min_y, int& max_y) {
        
        visit[x][y] = 1;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
            
        int dir[8] = {0, 1, 0, -1, -1, 0, 1, 0};
        
        for (int d = 0; d < 8; d += 2) {
            int xx = x + dir[d], yy = y + dir[d+1];        
            if (xx >= 0 && xx < image.size() && yy >= 0 && yy < image[x].size() && visit[xx][yy] == 0 && image[xx][yy] == '1') {
                dfs(image, visit, xx, yy, min_x, max_x, min_y, max_y);
            }
        }
    }
};


====== Other Solution, Binary Search is better than DFS! ========
public int minArea(char[][] image, int x, int y) {
    int m = image.length, n = image[0].length;
    int colMin = binarySearch(image, true, 0, y, 0, m, true);
    int colMax = binarySearch(image, true, y + 1, n, 0, m, false);
    int rowMin = binarySearch(image, false, 0, x, colMin, colMax, true);
    int rowMax = binarySearch(image, false, x + 1, m, colMin, colMax, false);
    return (rowMax - rowMin) * (colMax - colMin);
}

public int binarySearch(char[][] image, boolean horizontal, int lower, int upper, int min, int max, boolean goLower) {
    while(lower < upper) {
        int mid = lower + (upper - lower) / 2;
        boolean inside = false;
        for(int i = min; i < max; i++) {
            if((horizontal ? image[i][mid] : image[mid][i]) == '1') {
                inside = true; 
                break;
            }
        }
        if(inside == goLower) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }
    return lower;
}