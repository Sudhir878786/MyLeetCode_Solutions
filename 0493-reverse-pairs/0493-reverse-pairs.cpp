class Solution {
public:
    int ans=0;
    void func(vector<int>&nums,int start,int mid,int end)
    {
        int l=start;
        int r=mid+1;
        while(l<=mid and r<=end){
            if((long)nums[l]>(long)2*nums[r]){
                ans+=(mid-l+1);
                r++;
            }
            else{
                l++;
            }
        }
       sort(nums.begin() + start, nums.begin() + end + 1);
        return;
    }
    void merge(vector<int>&nums,int start,int end)
        
    {
        if(start>=end){
            return;
        }
        int mid=(start+end)/2;
        merge(nums,start,mid);
        merge(nums,mid+1,end);
        func(nums , start,mid,end);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        if(!n)return 0;
        merge(nums,0,n-1);
        return ans;
    }
};