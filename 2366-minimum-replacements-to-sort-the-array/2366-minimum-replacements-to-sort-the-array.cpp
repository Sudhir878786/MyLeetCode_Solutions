class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int last=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>last){
                // cout<<nums[i]<<endl;
                int req=nums[i]/last;
                if(nums[i]%last){ // if remainder
                    req++;
                }
                last=nums[i]/req;  // update the last for next itr
                ans+=req-1;
            }
            else{
                last=nums[i]; // uppdate last without replacemnt
            }
        }
        return ans;
    }
};