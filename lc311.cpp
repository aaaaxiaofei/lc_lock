311. Sparse Matrix Multiplication

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        // vector structure:
        // row of a, col of a, value of a
        // if col_of_a == row_of_b, do calculation, and put value to row_of_a and col_of_b
        
        if (A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0) 
            return {};
        
        // key: col_a, pair.first: row_of_a, pair.second: value_of_a
        unordered_map<int, vector<pair<int, int>>> m;
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] != 0) {
                    m[j].push_back(make_pair(i, A[i][j]));
                }
            }
        }
        
        for (int i = 0; i < B.size(); i++) {
            if (m.count(i) > 0) {
                for (int j = 0; j < B[i].size(); j++) {
                    if (B[i][j] != 0) {
                        for (auto p : m[i]) {
                            int row_a = p.first, val_a = p.second;
                            result[row_a][j] += val_a * B[i][j];
                        }
                    }
                }
            }
        }
        
        
        return result;
    }
};