class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        unordered_set<bool> oritations;
        int sz = points.size();
        for (int i = 0; i < sz; i++) {
            vector<int> p0 = points[i], p1 = points[(i+1)%sz], p2 = points[(i+2)%sz];
            int oritation = (p1[0]-p0[0])*(p2[1]-p1[1]) - (p1[1]-p0[1])*(p2[0]-p1[0]);
            if (oritation) {
                oritations.insert(oritation > 0);
            }
        }
        return oritations.size() == 1;
    }
};
