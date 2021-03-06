314. Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if (root == NULL) return {};
        
        vector<vector<int>> result;
        map<int, vector<int>> m;

        queue<TreeNode*> node;
        queue<int> order;
        
        node.push(root);
        order.push(0);
        
        while (!node.empty()) {
            
            TreeNode* cur = node.front();
            int x = order.front();
            node.pop(); order.pop();
            m[x].push_back(cur->val);
            
            if (cur->left) {
                node.push(cur->left);
                order.push(x-1);
            }
            if (cur->right) {
                node.push(cur->right);
                order.push(x+1);
            }
            
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        
        return result;
        
    }
    
};
