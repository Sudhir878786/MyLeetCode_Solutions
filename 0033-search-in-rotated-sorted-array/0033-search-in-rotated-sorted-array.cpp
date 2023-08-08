class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto it:mp){
            if(it.first==target){
                return it.second;
            }
        }
        return -1;
    }
};