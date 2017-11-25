261. Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        if (edges.size() != n - 1) return false;
        
        unordered_map<int, vector<int>> m;
        
        for (auto e : edges) {
            int a = e.first, b = e.second;
            m[a].push_back(b);
            m[b].push_back(a);
        }
        
        vector<int> visit(n, 0);
        dfs(m, 0, visit);
        
        int sum = 0;
        for (auto x : visit) sum += x;
        
        return sum == n;
        
    }
    
    void dfs(unordered_map<int, vector<int>>& m, int node, vector<int>& visit) {
        visit[node] = 1;
        for (auto num : m[node]) {
            if (visit[num] == 0) {
                dfs(m, num, visit);
            }
        }
    }
};


====== Check Cycle Solution =======
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes(n,0);
        for(int i=0; i<n; i++) nodes[i] = i;
        for(int i=0; i<edges.size(); i++){
            int f = edges[i].first;
            int s = edges[i].second;
            while(nodes[f]!=f) f = nodes[f];
            while(nodes[s]!=s) s = nodes[s];
            if(nodes[f] == nodes[s]) return false;
            nodes[s] = f;
        }
        return edges.size() == n-1;
    }
};