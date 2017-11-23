250. Count Univalue Subtrees

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.

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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        
        return count;
    }
    
    bool dfs(TreeNode* root, int& count) {
        
        if (root == NULL) return true;
        
        bool flag = dfs(root->left, count);
        flag &= dfs(root->right, count);
        
        if (root->left && root->val != root->left->val) flag = false;
        if (root->right && root->val != root->right->val) flag = false;
        
        if (flag) count++;

        return flag;
        
    }
};