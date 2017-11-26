285. Inorder Successor in BST

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        // if p is greater than cur, move to right
        // if p is less than cur, record cur val
        // if cur == p, and cur->right == Null, return val;
        
        TreeNode* result = nullptr;
        
        while (root) {
            if (p->val < root->val) {
                result = root;
                root = root->left;
            }
            else if (p->val >= root->val) {
                root = root->right;
            }
        }
        
        return result;
        
        
    }
};