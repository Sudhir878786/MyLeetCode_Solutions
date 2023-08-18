class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int>q1;  // min heap
        priority_queue<int,vector<int>,greater<>>q2;  // map heap
        long long n=nums.size()/3;
        vector<long long>temp(nums.size());
        long long cur_sm=0;
        for(int i=nums.size()-1;i>=n;i--){
            q2.push(nums[i]);
            cur_sm+=nums[i];
            if(q2.size()>n){
                cur_sm-=q2.top();
                q2.pop();
            }
            if(q2.size()==n){
                temp[i]=cur_sm;
            }
        }
        long long ans=LLONG_MAX;
        long long sum=0;
        for(int i=0;i<nums.size()-n;i++){
            q1.push(nums[i]);
            sum+=nums[i];
            if(q1.size()>n){
                sum-=q1.top();
                q1.pop();
            }
            if(q1.size()==n){
                ans=min(ans,sum-temp[i+1]);
            }
        }
        
        return ans;
        
    }
};