class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};