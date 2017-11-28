308. Range Sum Query 2D - Mutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n+1, 0));
        sum = move(v);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j+1] = sum[i][j] + matrix[i][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        
        int diff = sumRegion(row, col, row, col) - val;
            
        for (int j = col+1; j < sum[row].size(); j++) {
            sum[row][j] -= diff;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int result = 0;
        
        for (int i = row1; i <= row2; i++) {
            result += sum[i][col2+1] - sum[i][col1];
        }
        
        return result;
    }
private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */