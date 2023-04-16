class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int maxx=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxx){
                maxx=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxx;
    }
};