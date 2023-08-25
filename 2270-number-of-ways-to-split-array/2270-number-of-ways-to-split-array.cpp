class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int ans=0;
        long long cursum=0;
        for(int i=0;i<n-1;i++){
            cursum+=nums[i];  // left sum
            sum-=nums[i];  /// remove cur element from the total sum nresulting roght sum
            if(cursum>=sum){
                ans++;
            }
            
        }
        return ans;
    }
};