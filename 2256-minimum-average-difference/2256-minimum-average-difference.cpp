class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int ans=INT_MAX;
        int ind=0;
        for(auto it:nums)
        {
            sum+=it;
        }
    
        long long cursum=0;
        for(int i=0;i<n;i++){
            cursum+=nums[i];
            int avg1=(cursum)/(i+1);
            if(i==n-1){
                if(avg1<ans){
                    return n-1;
                }
                else{
                    break;
                }
            }
            int avg2=(sum-cursum)/(n-i-1);
            if(abs(avg1-avg2)<ans)
            {
                ans=abs(avg1-avg2);
                ind=i;
            }
        }
        return ind;
            
    }
};