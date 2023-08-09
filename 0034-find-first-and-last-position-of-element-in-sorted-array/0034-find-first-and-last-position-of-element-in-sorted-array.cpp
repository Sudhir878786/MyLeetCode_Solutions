class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int a=-1,b=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                a=i;
                // ans.push_back(i);
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                b=i;
                // ans.push_back(i);
                break;
            }
        }
        // ans.push_back();
        return {a,b};
    }
};