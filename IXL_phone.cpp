// Random Fibonacci Integer
int randomFibonacci(int n) {
  try{
    if (n < 0) 
      throw runtime_error("Input should be non-negative number\n");
    if (n == 0) return 0;

    vector<int> arr = {0, 1};

    while (arr.back() <= n)  {
      arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
    }

    arr.pop_back();

    int index = rand() % arr.size();

    return arr[index];
  }
  catch (const runtime_error& e) {
    cerr << e.what() << endl;
    throw;
  }
  
  return 0;
}

// Repeat Decimal
string repeatDecimal(int numerator, int denominator) {
  
  if (denominator == 0) return "";
  else if (numerator == 0) return "0";
   
  numerator = abs(numerator);
  denominator = abs(denominator);
  
  // Make sure the decimal is 0.****
  numerator %= denominator;
  
  unordered_map<int, int> m;
  string result = "";

  while (m.count(numerator) == 0) {
    m[numerator] = result.length();
    numerator *= 10;
    result += to_string(numerator / denominator);
    numerator %= denominator;
  }
  
  return result.substr(m[numerator]);
}
// Solution two
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        unordered_map<int, int> m;
        
        long long num = numerator;
        long long den = denominator;
        
        if (num % den == 0) {
            return to_string(num/den);
        }
        
        string sign = num * den < 0 ? "-" : "";        
        
        num = abs(num);
        den = abs(den);
        
        string result = sign + to_string(num / den) + ".";
        num %= den;

        while (num && m.count(num) == 0) {
            m[num] = result.length();
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }
        
        if (num == 0) return result;
        
        return result.substr(0, m[num]) + "(" + result.substr(m[num]) + ")";
    }
};


// Merge K list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Compare
{
public:
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;  
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) return NULL;
        ListNode pre(0);
        ListNode* cur = &pre;
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        
        for (auto node : lists) {
            if (node) q.push(node);
        }
        
        while (!q.empty()) {
            ListNode* node = q.top(); 
            q.pop();
            if (node->next) q.push(node->next);
            
            cur->next = node;
            cur = cur->next;
            
        }
        
        return pre.next;      
    }
};


// Linked List Palindrome
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
    
    bool check(ListNode*& head, ListNode* p) {
        if(!p) { return true; }
        bool isPal = check(head, p->next);
        if(head->val != p->val) {
            return false;
        }
        head = head->next;
        return isPal;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *slow(head), *fast(head);
        
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Make fast the head of right half.
        // Note that the right half may have one less node than left half
        fast = slow->next;
        
        slow->next = nullptr; // set tail of left half to be null
        
        
        // Right now slow is the head of left half,
        // fast is the head of right half
        
        bool reval(true);
        
        for (ListNode *left = head, *right = reverseList(fast); left && right; left = left->next, right = right->next) {
            if (left->val != right->val) {
                reval = false;
                reverseList(right); //reverse back
                break;
            }
        }
        
        slow->next = fast;
        
        return reval;
    }
private:
    ListNode* reverseList(ListNode *head) {
        ListNode dummy(0), *next(nullptr);
        
        while (head) {
            next = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = next;
        }
        
        return dummy.next;
    }
};


// Stickers to spell word
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        unordered_map<string, int> dp;
        // count characters a-z for each sticker 
        for (int i = 0; i < m; i++) 
            for (char c:stickers[i]) mp[i][c-'a']++;
        dp[""] = 0;
        return helper(dp, mp, target);
    }
private:
    int helper(unordered_map<string, int>& dp, vector<vector<int>>& mp, string target) {
        if (dp.count(target)) return dp[target];
        int ans = INT_MAX, n = mp.size();
        vector<int> tar(26, 0);
        for (char c:target) tar[c-'a']++;
        // try every sticker
        for (int i = 0; i < n; i++) {
            // optimization
            if (mp[i][target[0]-'a'] == 0) continue; 
            string s;
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++) 
                if (tar[j]-mp[i][j] > 0) s += string(tar[j]-mp[i][j], 'a'+j);
            int tmp = helper(dp, mp, s);
            if (tmp!= -1) ans = min(ans, 1+tmp);
        }
        dp[target] = ans == INT_MAX? -1:ans;
        return dp[target];
    }
};



// Level most appeared word
string mostLevelAppear(TreeNode* root) {
  
  // BFS go through the tree;
  // At each level, use a local hashtable to track appearance.
  // Another global hashtable track the appear time.
  // keep track of most frequent appeared string and it's frequency
  unordered_map<string, int> m;
  int max_freq = 0;
  string result = "";
  
  queue<TreeNode*> q;
  q.push(root);
  
  while (!q.empty()) {
    int n = q.size();
    unordered_map<string, int> mlocal;
    while (n--) {
      TreeNode* cur = q.front();
      q.pop();
      string str = cur->val;
      if (mlocal[str] == 0) {
        cout << "level " << level << " see a " << str << endl;
        mlocal[str] = 1;
        m[str]++;
        if (m[str] > max_freq) {
          max_freq = m[str];
          result = str;
        }
      }
      
      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }
  }
  return result;
}


// Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {       
        int val = amount + 1;
        vector<int> dp(amount + 1, val);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }        
        return dp[amount] == val ? -1 : dp[amount];
    }
};

// Combination sum
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};


// Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";       
        string prefix = strs[0];        
        for (auto word : strs) {           
            int j = 0;            
            while (j < min(word.size(), prefix.size()) && word[j] == prefix[j]) j++;            
            prefix = prefix.substr(0, j);
        }    
        return prefix;
    }
};

// Unique Path II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        
        if (obstacleGrid[0][0] == 1) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0 && i + j > 0) {
                    dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
                }
            }
        }
        
        return dp[m-1][n-1];
        
// O(n) space complexity solution
        //vector<int> dp(n, 0);
        // dp[0] = 1;
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (obstacleGrid[i][j] == 0) {
        //             dp[j] += j > 0 ? dp[j-1] : 0;
        //         }
        //         else
        //             dp[j] = 0;
        //     }
        // }
        
        // return dp[n-1];      
    }
};


// Kth largest 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {       
        priority_queue<int, vector<int>, greater<int>> q;      
        for (auto num : nums) {
            if (q.size() < k) q.push(num);
            else {
                if (num > q.top()) {
                    q.push(num);
                    q.pop();
                }
            }
        }       
        return q.top();
    }
};

// Symmetric Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};


// Permutation
class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    
    permuteRecursive(num, 0, result);
    return result;
  }
    
  void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)  {
    if (begin >= num.size()) {
        // one permutation instance
        result.push_back(num);
        return;
    }
    
    for (int i = begin; i < num.size(); i++) {
        swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, result);
        // reset
        swap(num[begin], num[i]);
    }
  }
};


// Count derangement
int countDer(int n)
{
    // Create an array to store counts for subproblems
    int der[n + 1];
 
    // Base cases
    der[1] = 0;
    der[2] = 1;
 
    // Fill der[0..n] in bottom up manner using above
    // recursive formula
    for (int i=3; i<=n; ++i)
        der[i] = (i-1)*(der[i-1] + der[i-2]);
 
    // Return result for n
    return der[n];
}


// String derangement
// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void helper(string str, int cur, unordered_map<char, vector<int>>& m, vector<string>& result) {

    if (cur == str.length() - 1) {
        result.push_back(str);
        return;
    }
    
    for (int i = cur + 1; i < str.length(); i++) {
        char c1 = str[cur], c2 = str[i];
        vector<int> v1 = m[c1], v2 = m[c2];
        if (find(v1.begin(), v1.end(), i) != v1.end() ||
            find(v2.begin(), v2.end(), cur) != v2.end()) continue;
        
        swap(str[cur], str[i]);
        helper(str, cur + 1, m, result);
        swap(str[cur], str[i]);
    }
}

vector<string> derange(string str) {
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < str.length(); i++) {
        m[str[i]].push_back(i);
    }
    vector<string> result;
    helper(str, 0, m, result);
    return result;
}


int main() {
    string str = "aabb";
    
    vector<string> v = derange(str);

    for (auto s : v) {
        cout << s << endl;
    }
}