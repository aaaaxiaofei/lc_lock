161. One Edit Distance

Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        int i = 0, j = 0;
        
        while (i < s.size() && j <t.size() && s[i] == t[j]) {
            i++; j++;
        }
        
        if (s.size() - i == 0) return t.size() - j == 1;
        else if (t.size() - j == 0) return s.size() - i == 1;
        
        string s1 = s.substr(i+1), t1 = t.substr(j+1);

        if (s1.size() == t1.size()) return s1 == t1;
        else {
            return s1.size() > t1.size() ? (s1 == t.substr(j)) : (s.substr(i) == t1);
        }
    }
};