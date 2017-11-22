243. Shortest Word Distance

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int w1 = -1, w2 = -1, min_dist = INT_MAX;
        
        for (int i = 0; i < words.size(); i++) {
            
            if (words[i] == word1) w1 = i;
            if (words[i] == word2) w2 = i;
            
            if (w1 >= 0 && w2 >= 0) min_dist = min(min_dist, std::abs(w1-w2));
        }
        
        return min_dist;
    }
};