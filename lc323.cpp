323. Number of Connected Components in an Undirected Graph


Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        // if both -1, use larger one as root, count++
        // find both root, if equals, do nothing
        // if different and one is -1, set to larger root
        // if different and neither is -1, count--
        
        vector<int> root(n, -1);
        int count = n;
        
        for (auto e : edges) {
            int a = e.first, b = e.second;
            if (root[a] == -1 && root[b] == -1) {
                root[a] = root[b] = max(a, b);
                count--;
            }
            else if (root[a] != -1 && root[b] != -1) {
                while (root[a] != a) {
                    root[a] = root[root[a]];
                    a = root[a];
                }
                while (root[b] != b) {
                    root[b] = root[root[b]];
                    b = root[b];
                }
                if (a != b) {
                    root[a] = root[b] = max(a, b);
                    count--;
                }
            }
            else {
                root[a] = root[b] = max(root[a], root[b]);
                count--;
            }
        }
        
        return count;
    }
};