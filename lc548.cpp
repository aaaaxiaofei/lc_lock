 548. Split Array with Equal Sum

 Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
Note:
1 <= n <= 2000.
Elements in the given array will be in range [-1,000,000, 1,000,000].


class Solution {
public:
    bool splitArray(vector<int>& nums) {
    
        vector<int> sum(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            sum[i] = nums[i] + (i > 0 ? sum[i-1] : 0);
        }
        
        for (int i = 1; i+5 < nums.size(); i++) {
            for (int k = nums.size()-2; k >= i + 4; k--) {
                if (sum[i-1] == sum.back() - sum[k]) {
                    for (int j = i + 2; j <= k - 2; j++) {
                        if (sum[i-1] == sum[j-1] - sum[i] && sum[i-1] == sum[k-1] - sum[j])
                            return true;
                    }
                }
            }
        }
        
        return false;
        
        
    }
};



======= Other Solution (Middle Cut first) ======

Just think this problem as a DFS. What we need is to search for 3 positions (i, j, k) and see if they divide the array to 4 parts with same summary. Some tricks:

Calculate left on the fly. Thus at last we don't need to calc summary of the 4th part.
Skip 0 during calculate target because adding zero won't change it.
public class Solution {
    public boolean splitArray(int[] nums) {
        int sum = 0, target = 0;
        for (int num : nums) sum += num;
        for (int i = 1; i + 5 < nums.length; i++) {
            if (i != 1 && nums[i - 1] == 0  && nums[i] == 0) continue;
            target += nums[i - 1];
            if (dfs(nums, i + 1, target, sum - target - nums[i], 1)) return true;
        }
        return false;
    }
    
    private boolean dfs(int[] nums, int start, int target, int left, int depth) {
        if (depth == 3) {
            if (left == target) return true;
            return false;
        }
        
        int sub = 0;
        for (int j = start + 1; j + 5 - depth * 2 < nums.length; j++) {
            sub += nums[j - 1];
            if (sub == target) {
                if (dfs(nums, j + 1, target, left - sub - nums[j], depth + 1)) {
                    return true;
                }
            }
        }
        
        return false;
    }
}