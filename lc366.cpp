366. Find Leaves of Binary Tree

Given a binary tree, collect a trees nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root == NULL) return {};
        map<int, vector<int>> m;
        vector<vector<int>> result;
        
        dfs(root, m);
        
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);    
        }
        
        return result;
    }
    
    int dfs(TreeNode* root, map<int, vector<int>>& m) {
        if (root == NULL) return 0;
        
        int depth = 1 + max(dfs(root->left, m), dfs(root->right, m));
        m[depth].push_back(root->val);
        
        return depth;
    }
};

======= Other Solution No Hashing ==========
  public class Solution {
        public List<List<Integer>> findLeaves(TreeNode root) {
            List<List<Integer>> list = new ArrayList<>();
            findLeavesHelper(list, root);
            return list;
        }
        
  // return the level of root
        private int findLeavesHelper(List<List<Integer>> list, TreeNode root) {
            if (root == null) {
                return -1;
            }
            int leftLevel = findLeavesHelper(list, root.left);
            int rightLevel = findLeavesHelper(list, root.right);
            int level = Math.max(leftLevel, rightLevel) + 1;
            if (list.size() == level) {
                list.add(new ArrayList<>());
            }
            list.get(level).add(root.val);
            root.left = root.right = null;
            return level;
        }
    }