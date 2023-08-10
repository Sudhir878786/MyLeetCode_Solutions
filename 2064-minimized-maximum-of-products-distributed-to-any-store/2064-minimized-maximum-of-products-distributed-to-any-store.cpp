class Solution {
public:
    int minimizedMaximum(int n, vector<int>& nums) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=(l+r)/2;
            int cur=0;
            for(int i=0;i<nums.size();i++){
                cur+=(long long)ceil(1.0*nums[i]/mid);
            }
            if(cur>n){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};