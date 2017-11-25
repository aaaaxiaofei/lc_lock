265. Paint House II

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?


class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        
        int m = costs.size(), n = costs[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, 0));
        int first_index = -1, second_index = -1;
        
        for (int i = 0; i < m; i++) {
            
            int first = INT_MAX, second = INT_MAX;
            
            if (i == 0) {
                for (int j = 0; j < n; j++) {
                    result[i][j] = costs[i][j];
                    if (costs[i][j] <= first) {
                        second = first;
                        second_index = first_index;
                        first = costs[i][j];
                        first_index = j;
                    }    
                    else if (costs[i][j] < second) {
                        second = costs[i][j];
                        second_index = j;
                    }
                }
            }
            else {
                int local_second_index = -1, local_first_index = -1;
                for (int j = 0; j < n; j++) {
                    if (j == first_index) {
                        result[i][j] = costs[i][j] + result[i-1][second_index];
                    }
                    else {
                        result[i][j] = costs[i][j] + result[i-1][first_index];
                    }
                    
                    if (result[i][j] <= first) {
                        second = first;
                        local_second_index = local_first_index;
                        first = result[i][j];
                        local_first_index = j;
                    }
                    else if (result[i][j] < second) {
                        second = result[i][j];
                        local_second_index = j;
                    }
                }
                first_index = local_first_index;
                second_index = local_second_index;

            }     
        }
        
        int min_cost = INT_MAX;
        for (auto x : result.back()) {
            min_cost = min(min_cost, x);
        }
        
        return min_cost;
    }
};




====== Other solution =======:

int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if(n==0) return 0;
    int k = costs[0].size();
    if(k==1) return costs[0][0];

    vector<int> dp(k, 0);
    int min1, min2;

    for(int i=0; i<n; ++i){
        int min1_old = (i==0)?0:min1;
        int min2_old = (i==0)?0:min2;
        min1 = INT_MAX;
        min2 = INT_MAX;
        for(int j=0; j<k; ++j){
            if(dp[j]!=min1_old || min1_old==min2_old){
                dp[j] = min1_old + costs[i][j];
            }else{//min1_old occurred when painting house i-1 with color j, so it cannot be added to dp[j]
                dp[j] = min2_old + costs[i][j];
            }

            if(min1<=dp[j]){
                min2 = min(min2, dp[j]);
            }else{
                min2 = min1;
                min1 = dp[j];
            }
        }
    }

    return min1;
}