class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int left=l[i];
            int right=r[i];
            vector<int>cur(nums.begin()+left,nums.begin()+1+right);
            sort(cur.begin(),cur.end());
            if(cur.size()<2){
                ans.push_back(false);
                // continue;
            }
            int diff=cur[1]-cur[0];
            bool st=true;
            for(int j=2;j<cur.size();j++){
                if(cur[j]-cur[j-1]!=diff){
                    st=false;
                    // break;
                }
                
            }
            ans.push_back(st);
            
            
        }
        return ans;
    }
};