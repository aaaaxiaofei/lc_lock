487. Max Consecutive Ones II

Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        // skip all zeros
        // count continuous ones
        // when meet a zero, stop counting and save count to pre
        // 
        if (nums.size() == 0) return 0;
        
        int i = 0, left = 0, right = 0, result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            right++;
            if (nums[i] == 0) {
                left = right;
                right = 0;
            }
            result = max(result, left + right);
        }
        
        return result;
    }
};