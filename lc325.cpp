325. Maximum Size Subarray Sum Equals k

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isnt one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int len = 0, sum = 0;
        m[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.count(sum) == 0) {
                m[sum] = i;
            }
            if (m.count(sum-k) > 0)
                len = max(len, i - m[sum-k]);
        }
        
        return len;
        
    }
};