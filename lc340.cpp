340. Longest Substring with At Most K Distinct Characters

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if (s.size() == 0 || k == 0) return 0;
        
        unordered_map<char, int> m;
        int diff = 0, i = 0, j = 0, result = 0;
        
        while (j < s.size()) {
            while (j < s.size()) {
                if (++m[s[j]] == 1) 
                    if (++diff > k)
                        break;
                j++;
            }
            
            result = max(result, j - i);
            while (diff > k) {
                m[s[i]]--;
                if (m[s[i]] == 0) 
                    diff--;
                i++;
            }
            j++;
        }
        
        return result;
    }
};