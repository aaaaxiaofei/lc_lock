156. Binary Tree Upside Down

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) 
or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},

    1
   / \
  2   3
 / \
4   5

return the root of the binary tree [4,5,2,#,#,3,1].

   4
  / \
 5   2
    / \
   3   1  

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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        
        if (root == NULL) return NULL;
        if (root->left == NULL) return root;
        
        TreeNode* l = root->left;
        TreeNode* new_head = upsideDownBinaryTree(l);
        
        TreeNode* cur = new_head;
        while (cur->right) cur = cur->right;
        
        cur->left = root->right;
        cur->right = root;
        root->left = NULL;
        root->right = NULL;
        
        return new_head;
        
    }
};


Java recursive:
public TreeNode upsideDownBinaryTree(TreeNode root) {
    TreeNode curr = root;
    TreeNode next = null;
    TreeNode temp = null;
    TreeNode prev = null;
    
    while(curr != null) {
        next = curr.left;
        
        // swapping nodes now, need temp to keep the previous right child
        curr.left = temp;
        temp = curr.right;
        curr.right = prev;
        
        prev = curr;
        curr = next;
    }
    return prev;
}  