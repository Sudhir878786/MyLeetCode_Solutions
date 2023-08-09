class Solution {
public:
    int search(vector<int>& nums, int target) {
//         unordered_map<int,int>mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]=i;
//         }
//         for(auto it:mp){
            
//             if(it.first==target){
//                 return it.second;
//             }
//         }
//         return -1;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target and nums[mid]>=target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]<=target and nums[r]>=target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};