666. Path Sum IV

If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.

class Solution {
public:
    int pathSum(vector<int>& nums) {
        const int MAX_LEVEL = 5;
        int nodes[MAX_LEVEL + 1][(int) pow(2, MAX_LEVEL)] = {0};
        int max_depth;
        int sum = 0;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            int val = num % 10; num /= 10;
            int col = num % 10; num /= 10;
            int row = num;
                        
            nodes[row - 1][col - 1] = max(nodes[row][2 * (col - 1)] + nodes[row][2 * (col - 1) + 1], 1);
            
            sum += val * nodes[row - 1][col - 1];
        }
        return sum;
    }
};