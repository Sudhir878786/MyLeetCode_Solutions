class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        //vector<int>dup(nums.begin(),nums.end());
        int n=nums.size();
       // reverse(dup.begin(),dup.end());
        vector<int>left(n,0),right(n,0),ans(n);
        
        left[0]=0;
        
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
        }
        //right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};