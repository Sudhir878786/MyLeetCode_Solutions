class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>=nums[l]){
                if(nums[l]<=target and nums[mid]>=target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }else{
                if(nums[mid]<=target and nums[r]>=target)
                {
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        return false;
    }
};