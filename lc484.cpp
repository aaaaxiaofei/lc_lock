484. Find Permutation

By now, you are given a secret signature consisting of character 'D' and 'I'. 'D' represents a decreasing relationship between two numbers, 'I' represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can't represent the "DI" secret signature.

On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could refer to the given secret signature in the input.

Example 1:
Input: "I"
Output: [1,2]
Explanation: [1,2] is the only legal initial spectial string can construct secret signature "I", where the number 1 and 2 construct an increasing relationship.
Example 2:
Input: "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI", 
but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
Note:

The input string will only contain the character 'D' and 'I'.
The length of input string is a positive integer and will not exceed 10,000

class Solution {
public:
    vector<int> findPermutation(string s) {
        // if last one is I, always put the largest number in the back
        // else if last one is D
        
        int n = s.size() + 1, cur = s.size() - 1;
        vector<int> result;
        stack<int> stk;
        
        while (cur >= 0) {
            if (s[cur] == 'I') {
                result.push_back(n--);
                while (!stk.empty()) {
                    result.push_back(stk.top());
                    stk.pop();
                }
            }
            else {
                stk.push(n--);
            }
            cur--;
        }
        result.push_back(1);
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

};


======= Other Solution ======
  vector<int> ret;
  for (int i = 0; i <= s.size(); ++i)
    if (i == s.size() || s[i] == 'I')
      for (int j = i + 1, lenTmp = ret.size(); j > lenTmp; --j)
        ret.push_back(j);
  return ret;