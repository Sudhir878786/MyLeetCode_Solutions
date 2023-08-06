class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=nums[0];
        int cur_sum=nums[0];
        int max_start=0;
        int max_end=0;
        int cur_start=0;
        for(int i=1;i<n;i++){
            if(cur_sum<0){
                cur_sum=nums[i];
                cur_start=i;
                
            }
            else cur_sum+=nums[i];
            if(cur_sum>max_sum){
                max_sum=cur_sum;
                max_start=cur_start;
                max_end=i;
            }
            
        }
        return max_sum;
        
    }
};