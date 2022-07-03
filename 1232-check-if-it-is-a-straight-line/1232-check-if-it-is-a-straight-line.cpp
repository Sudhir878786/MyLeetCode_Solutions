class Solution {
public:
   bool checkStraightLine(vector<vector<int>>& points) {
        int len = points.size();
        if(len == 1) return false;
        if(len == 2) return true;
        int dx = points[1][0] - points[0][0], dy = points[1][1] - points[0][1];
        for(int i = 2; i < len; i++)
            if(dx*(points[i][1] - points[0][1]) != dy*(points[i][0] - points[0][0]))
                return false;
        return true;
    }

};