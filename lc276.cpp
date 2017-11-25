276. Paint Fence

There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.


class Solution {
public:
    int numWays(int n, int k) {
        
        if (n == 0 || k == 0) return 0;
        
        vector<int> same(n, 0), diff(n, 0);
        same[0] = 0; diff[0] = k;
        
        for (int i = 1; i < n; i++) {
            same[i] = diff[i-1];
            diff[i] = (k-1)*(same[i-1] + diff[i-1]);
        }
        
        return same.back() + diff.back();
    }
};