469. Convex Polygon

Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). 
In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise dont intersect each other.
Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        vector<vector<int>> p = points;
        for (long i = 0, n = p.size(), prev = 0, cur; i < n; i++)
            if (cur = det2({p[i], p[(i+1)%n], p[(i+2)%n]})) { 
              if (cur*prev < 0) return false; 
              else prev = cur;
            }

      return true;
        
    }
        
    long det2(const vector<vector<int>>& A) {
    	int aa = (A[1][0]-A[0][0])*(A[2][1]-A[0][1]) - (A[1][1]-A[0][1])*(A[2][0]-A[0][0]);
        printf("see det: %d \n", aa);
        return aa;
    }
};