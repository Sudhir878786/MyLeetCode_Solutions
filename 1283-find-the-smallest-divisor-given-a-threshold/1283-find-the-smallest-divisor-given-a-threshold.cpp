class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int n=nums.size();
        int l=1,r=*max_element(nums.begin(),nums.end());
        
        while(l<=r){
            int mid=(l+r)/2;
            int cur=0;
            for(int i=0;i<n;i++){
                cur+=((nums[i]-1)/mid)+1;
            }
            if(cur>th){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};