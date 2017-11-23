245. Shortest Word Distance III

This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        // meet word1 or word2, record i;
        // meet next word1 or word2, if not the previous one or if word1 == word2, update dist
        // update cur and word
        
        int cur = -1, min_dist = INT_MAX;
        string pre;
        
        for (int i = 0; i < words.size(); i++) {
                 
            if (words[i] == word1 || words[i] == word2) {
                if (cur != -1 && (words[i] != pre || word1 == word2)) {
                    min_dist = min(min_dist, i - cur);
                }
                cur = i;
                pre = words[i];
            }
        }
        
        return min_dist;
    }
};