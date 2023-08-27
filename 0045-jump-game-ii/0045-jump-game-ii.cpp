class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        int ans=0;
        int cur=0;
        for(int i=0;i<n-1;i++){
            reach=max(reach,i+nums[i]);
            // cout<<reach<<"reach"<<endl;
            if(i==cur){
                cur=reach;
                ans++;
            }
        }
        return ans;
    }
};