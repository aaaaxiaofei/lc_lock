358. Rearrange String k Distance Apart

Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
s = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
s = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
s = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

class Solution {
    
struct Node {
    int val;
    char c;
    Node(int v, char ch) : val(v), c(ch) {}
};

struct Comp {
    bool operator() (Node a, Node b) {
        return a.val < b.val;
    }
};
    

public:
    string rearrangeString(string s, int k) {
        // Go through every char, check total number of each char, 
        //      max number of a char, and how many max number
        
        // check k*(max_num - 1) + num_of_max_num <= s.size()
        
        unordered_map<char, int> m;
        priority_queue<Node, vector<Node>, Comp> q;
        
        for (auto c : s) {
            m[c]++;
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            Node nd(it->second, it->first);
            q.push(nd);
        }
        
        string result;
        unordered_map<char, int> pos;
        stack<Node> stk;
        
        while (!q.empty()) {
            Node nd = q.top(); q.pop();
            if (pos.count(nd.c) && result.size() - pos[nd.c] < k)
                stk.push(nd);
            else {
                pos[nd.c] = result.size();
                result += nd.c;
                nd.val--;
                if (nd.val > 0) 
                    q.push(nd);
                while (!stk.empty()) {
                    q.push(stk.top());
                    stk.pop();
                }
            }
        }
        
        if (!stk.empty()) return "";
        
        
        return result;
    }
};


====== Solution 2 ==========
class Solution {
    
public:
    string rearrangeString(string s, int k) {
        
        if (k == 0) return s;
        
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        string result;
        int remain = s.size();
        
        for (auto c : s) m[c]++;

        for (auto it = m.begin(); it != m.end(); it++) {
            q.push(make_pair(it->second, it->first));
        }
        

        while (!q.empty()) {
            
            stack<pair<int, char>> stk;
            int len = min(k, remain);
            
            for (int i = 0; i < len; i++) {
                if (q.empty()) return "";
                
                pair<int, char> p = q.top(); 
                q.pop();
                result += p.second;
                if (--p.first > 0) stk.push(p);
                remain--;
            }
            
            while (!stk.empty()) {
                q.push(stk.top());
                stk.pop();
            }
        }
           
        return result.size() < s.size() ? "" : result;
    }
};


======= Solution 3 ========
public class Solution {
    public String rearrangeString(String str, int k) {
        int length = str.length();
        int[] count = new int[26];
        int[] valid = new int[26];
        for(int i=0;i<length;i++){
            count[str.charAt(i)-'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for(int index = 0;index<length;index++){
            int candidatePos = findValidMax(count, valid, index);
            if( candidatePos == -1) return "";
            count[candidatePos]--;
            valid[candidatePos] = index+k;
            sb.append((char)('a'+candidatePos));
        }
        return sb.toString();
    }
    
   private int findValidMax(int[] count, int[] valid, int index){
       int max = Integer.MIN_VALUE;
       int candidatePos = -1;
       for(int i=0;i<count.length;i++){
           if(count[i]>0 && count[i]>max && index>=valid[i]){
               max = count[i];
               candidatePos = i;
           }
       }
       return candidatePos;
   }
}