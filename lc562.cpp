562. Longest Line of Consecutive One in Matrix

Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.

class Solution {
public:
    struct Node {
        int horizon;
        int vertical;
        int diag;
        int adiag;
        Node(int h, int v, int d, int ad) : horizon(h), vertical(v), diag(d), adiag(ad) {};
    };
    
    int longestLine(vector<vector<int>>& M) {
        
        if (M.size() == 0 || M[0].size() == 0) return 0;
        Node node(0, 0, 0, 0);
        vector<vector<Node>> m(M.size(), vector<Node>(M[0].size(), node));
        int result = 0;
        
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {         
                if (M[i][j] == 1) {
                    m[i][j].vertical = 1 + (i > 0 ? m[i-1][j].vertical : 0) ;
                    m[i][j].horizon = 1 + (j > 0 ? m[i][j-1].horizon : 0);
                    m[i][j].diag = 1 + (i > 0 && j > 0 ? m[i-1][j-1].diag : 0);
                    m[i][j].adiag = 1 + (i > 0 && j < m[i].size()-1 ? m[i-1][j+1].adiag : 0);
                    
                    result = max(result, m[i][j].vertical);
                    result = max(result, m[i][j].horizon);
                    result = max(result, m[i][j].diag);
                    result = max(result,m[i][j].adiag);
                } 
            }
        }
        
        return result;
    }
};



======= DP also works here =======
public int longestLine(int[][] M) {
    int n = M.length, max = 0;
    if (n == 0) return max;
    int m = M[0].length;
    int[][][] dp = new int[n][m][4];
    for (int i=0;i<n;i++) 
        for (int j=0;j<m;j++) {
            if (M[i][j] == 0) continue;
            for (int k=0;k<4;k++) dp[i][j][k] = 1;
            if (j > 0) dp[i][j][0] += dp[i][j-1][0]; // horizontal line
            if (j > 0 && i > 0) dp[i][j][1] += dp[i-1][j-1][1]; // anti-diagonal line
            if (i > 0) dp[i][j][2] += dp[i-1][j][2]; // vertical line
            if (j < m-1 && i > 0) dp[i][j][3] += dp[i-1][j+1][3]; // diagonal line
            max = Math.max(max, Math.max(dp[i][j][0], dp[i][j][1]));
            max = Math.max(max, Math.max(dp[i][j][2], dp[i][j][3]));
        }
    return max;
}