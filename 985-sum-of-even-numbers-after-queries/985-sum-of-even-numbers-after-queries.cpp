class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>v;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                sum+=nums[i];
            }
        } 
        
        for(int i=0;i<q.size();i++){
            int val=q[i][0];
            int ind=q[i][1];
            if((val+nums[ind])%2==0){
                if(nums[ind]%2!=0){
                sum+=val+nums[ind];
                }
                else{
                    sum+=val;
                }
                
            }
            
            else if((val+nums[ind]%2!=0) and nums[ind]%2==0){
                sum-=nums[ind];
            }
            nums[ind]+=val;
            v.push_back(sum);
        }
       
        return v;
              
        
        
    
        
    }
};