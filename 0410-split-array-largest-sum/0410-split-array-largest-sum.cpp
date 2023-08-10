class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int cur=0;
            int cnt=1;
            for(int i=0;i<n;i++){
                if(cur+nums[i]>mid){
                    cnt++;
                    cur=nums[i];
                }
                else cur+=nums[i];
            }
            if(cnt>m){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
       
        
    }
   
};