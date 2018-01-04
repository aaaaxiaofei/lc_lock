		1
	   / \
	  2	  3
	 / \   
	4 	5

(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1

//=====================
// 		Preorder
//=====================

// Recursive:
vector<int> preorderTraversal(TreeNode* root) {
    // Root, left, right
    vector<int> result;
    helper(root, result);
    return result;
}

void helper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    result.push_back(root->val);
    helper(root->left, result);
    helper(root->right, result);
}

// Iterative
vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    stack<TreeNode*> s;
    s.push(root);
    
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();           
        result.push_back(node->val);
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return result;
}


//=====================
// 		Ineorder
//=====================
// Recursive:
vector<int> inorderTraversal(TreeNode* root) {
    // Left, root, right
    vector<int> result;
    helper(root, result);
    return result;
}

void helper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    helper(root->left, result);
    result.push_back(root->val);
    helper(root->right, result);
}

// Iterative
vector<int> inorderTraversal(TreeNode* root) {
    // Left, root, right
    vector<int> result;
    stack<TreeNode*> stk;        
    while (root || !stk.empty()) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        result.push_back(root->val);
        root = root->right;
    }       
    return result;
}

//=====================
// 		Postorder
//=====================
vector<int> postorderTraversal(TreeNode* root) {      
    // left, right, root
    // Let's do the reverse, root, right, left
    if (!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);        
    while (!stk.empty()) {
        TreeNode* cur = stk.top();
        stk.pop();
        result.push_back(cur->val);
        if (cur->left) stk.push(cur->left);
        if (cur->right) stk.push(cur->right);
    }
           
    reverse(result.begin(), result.end());
    return result;
}

// Other's solution:
vector<int> nodes;
stack<TreeNode*> toVisit;
TreeNode* curNode = root;
TreeNode* lastNode = NULL;
while (curNode || !toVisit.empty()) {
    if (curNode) {
        toVisit.push(curNode);
        curNode = curNode -> left;
    }
    else {
        TreeNode* topNode = toVisit.top();
        if (topNode -> right && lastNode != topNode -> right)
            curNode = topNode -> right;
        else {
            nodes.push_back(topNode -> val);
            lastNode = topNode;
            toVisit.pop();
        }
    }
}
return nodes;