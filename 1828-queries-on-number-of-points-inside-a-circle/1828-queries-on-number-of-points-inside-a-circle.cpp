class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries){
            int rad=q[2]*q[2];
            int count=0;
            for(auto p:points){
                if(((q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]))<=rad){
                    count++;
                }
            }
            ans.push_back(count);
            
            
        }
        return ans;
    }
};