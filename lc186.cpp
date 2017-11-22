186. Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array

Update (2017-10-16):
We have updated the function signature to accept a character array, so please reset to the default code 
definition by clicking on the reload button above the code editor. Also, Run Code is now available!

class Solution {
public:
    void reverseWords(vector<char>& str) {
        
        int i = 0, j = 0;
        
        while (j < str.size()) {
            while (j < str.size() && str[j] != ' ') j++;
            reverseString(str, i, j-1);
            while (j < str.size() && str[j] == ' ') j++;
            i = j;
        }
        
        reverseString(str, 0, str.size()-1);
    }
    
    void reverseString(vector<char>& str, int i, int j) {
        while (i < j) swap(str[i++], str[j--]);
    }
};


Using STL:
void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    for (int i = 0, j = 0; i < s.size(); i = j + 1) {
        for (j = i; j < s.size() && !isblank(s[j]); ++j);
        reverse(s.begin()+i, s.begin()+j);
    }
}
