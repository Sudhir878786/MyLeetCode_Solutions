class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        // use 3 monotonic stack
        stack<int>st1,st2,temp;
        vector<int>ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(st1.size() and nums[i]>nums[st1.top()]){
                temp.push(st1.top());
                st1.pop();
            }
            while(st2.size() and nums[i]>nums[st2.top()]){
                ans[st2.top()]=nums[i];
                st2.pop();
            }
            while(temp.size()){
                st2.push(temp.top());
                temp.pop();
            }
            
            st1.push(i);
        }
        return ans;
    }
};