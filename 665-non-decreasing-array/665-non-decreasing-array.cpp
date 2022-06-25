class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
           int count=0;
        for(int i=1;i<nums.size();i++){
           if(nums[i-1]>nums[i]){
               if(i==1) count++;
               else{
                   if(nums[i]<nums[i-2] && (i<nums.size()-1 && nums[i+1]<=nums[i-1])) return false;
				//**UPDATED CONDTION ADDED IN THE CODE**
                   else count++;
               }
           }
            if(count>1) return false;
            
        }
        
        return true;
    }
};