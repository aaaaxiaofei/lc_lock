298. Binary Tree Longest Consecutive Sequence


Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

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
    int longestConsecutive(TreeNode* root) {
        
        // dfs to left, right;
        // if cur is equal to pre value + 1, then lenght++, update result
        
        if (root == NULL) return 0;
        
        int result = 1;
        
        dfs(root, root->val, 0, result);
        
        return result;
    }
    
    void dfs(TreeNode* root, int cur, int len, int & result) {
        if (root != NULL) {
            if (root->val == cur+1) {
                result = max(result, ++len);
            }
            else 
                len = 1;
            dfs(root->left, root->val, len, result);
            dfs(root->right, root->val, len, result);
            
            
        } 
    }
};