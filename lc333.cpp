333. Largest BST Subtree

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int result = 0;
        int vmin = 0, vmax = 0;
        dfs(root, vmin, vmax, result);
        return result;
    }
    
    bool dfs(TreeNode* root, int& vmin, int& vmax, int& result) {
        
        if (root == NULL) return true;
        
        int left_min, left_max, right_min, right_max;
        int l_result = 0, r_result = 0;
        
        bool flag_left = dfs(root->left, left_min, left_max, l_result);
        bool flag_right = dfs(root->right, right_min, right_max, r_result);
        
        if (flag_left && flag_right) {
            if ((!root->left || root->val > left_max) && 
                (!root->right || root->val < right_min)) {
                result = l_result + 1 + r_result;
                vmin = root->left ? left_min : root->val;
                vmax = root->right ? right_max : root->val;
                return true;
            }
        }
        
        result = max(l_result, r_result);
        return false;
    }
};
