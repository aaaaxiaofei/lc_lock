266. Palindrome Permutation

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char, int> m;
        int odd = 0;
        for (auto c : s) {
            if ((++m[c])%2 == 1) odd++;
            else odd--;
        }
        return odd < 2;
    }
};