class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int j=0;
        ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            if(ans[j][1]<intervals[i][0]){
                ans.push_back(intervals[i]);
                j++;
            }else if(ans[j][1]<intervals[i][1]){
                ans[j][1]=intervals[i][1];
            }
        }
        return ans;
    }
};