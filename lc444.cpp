444. Sequence Reconstruction

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true
UPDATE (2017/1/8):
The seqs parameter had been changed to a list of list of strings (instead of a 2d array of strings). Please reload the code definition to get the latest changes.

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        if (org.size() == 0) return true;
        if (seqs.size() == 0) return false;
        
        unordered_map<int, vector<int>> follow;
        unordered_map<int, int> before;
        set<int> s;

        for (int i = 0; i < seqs.size(); i++) {
            if (seqs[i].size()) s.insert(seqs[i][0]);
            for (int j = 1; j < seqs[i].size(); j++) {
                s.insert(seqs[i][j]);
                follow[seqs[i][j-1]].push_back(seqs[i][j]);
                before[seqs[i][j]]++;
            }
        }
        
        if (s.size() != org.size()) return false;
        
        stack<int> q;
        q.push(org[0]);
        int cur = 0;
        
        while (q.size() == 1) {
            int head = q.top(); q.pop();
            
            if (cur >= org.size() || head != org[cur++]) return false;
            
            for (auto num : follow[head])
                if (--before[num] == 0)
                    q.push(num);
        }
        
        return q.size() == 0 && cur == org.size();
        

    }
};


=========  Good solution =========
After reading a few posts on this topic, I guess most of people over-think about this problem.

IMHO, We dont need to implement any graph theory expressively here; rather, it is sufficient to just check if every two adjacent elements also appears adjacently in the sub-sequences. (and of course, some basic boundary checking is also necessary)

in C++:

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size()+1);
        for(int i=0;i<org.size();++i) pos[org[i]] = i;
        
        vector<char> flags(org.size()+1,0);
        int toMatch = org.size()-1;
        for(const auto& v : seqs) {
            for(int i=0;i<v.size();++i) {
                if(v[i] <=0 || v[i] >org.size())return false;
                if(i==0)continue;
                int x = v[i-1], y = v[i];
                if(pos[x] >= pos[y]) return false;
                if(flags[x] == 0 && pos[x]+1 == pos[y]) flags[x] = 1, --toMatch;
            }
        }
        return toMatch == 0;
    }