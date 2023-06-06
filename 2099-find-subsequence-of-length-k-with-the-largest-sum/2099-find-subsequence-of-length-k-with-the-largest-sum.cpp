class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            int minn=min_element(ans.begin(),ans.end())-ans.begin();
            if(ans[minn]<nums[i]){
                ans.erase(ans.begin()+minn);
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};