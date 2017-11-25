255. Verify Preorder Sequence in Binary Search Tree

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        
        // if a number is smaller than top, then push into stack
        // if it is greater than the top, pop, keep track of the last poped one
        
        stack<int> s;
        int lower = INT_MIN;
        
        for (auto num : preorder) {
            if (num < lower) return false;

            while (!s.empty() && num > s.top()) {
                lower = max(lower, s.top());
                s.pop();
            }
            
            s.push(num);
        }
        
        return true;
    }
};


======= O(1) space solution ======
public boolean verifyPreorder(int[] preorder) {
    int low = Integer.MIN_VALUE, i = -1;
    for (int p : preorder) {
        if (p < low)
            return false;
        while (i >= 0 && p > preorder[i])
            low = preorder[i--];
        preorder[++i] = p;
    }
    return true;
}