class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        long long pre=0;
        for(int i=0;i<n;i++){
            pre+=nums[i]; 
            ans=max(ans,(pre+i)/(i+1));
        }
        
        
        return ans;
    }
};