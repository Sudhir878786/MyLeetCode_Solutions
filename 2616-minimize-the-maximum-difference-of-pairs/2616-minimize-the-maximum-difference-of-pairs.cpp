class Solution {
public:
    bool can(vector<int>&nums,int mid,int p)
    {
        int ans=0;
        for(int i=0;i<nums.size()-1;)
        {
            
            if(nums[i+1]-nums[i]<=mid){
                // cout<<"jbkj";
                ans++;
                i+=2;
            }
            else{
                i++;
            }
        }
        cout<<"ans"<<ans<<endl;
        return ans>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums.front();
        // cout<<can(nums,1,p)<<endl;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            // cout<<mid<<endl;
            if(can(nums,mid,p)){
                // cout<<"kjnakjf"<<endl;
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};