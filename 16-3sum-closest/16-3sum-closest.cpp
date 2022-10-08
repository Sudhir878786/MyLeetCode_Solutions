class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    
        // Initialize some neccessary variables
          int n=nums.size();
          int result;
          int diff=INT_MAX;
        
        // Sort the array in ascending order: O(nlogn)
          sort(nums.begin(),nums.end());
        
        // Use Two Pointer For Optimization: O(n^2)
          for(int i=0;i<n-2;i++)
          {
              int start=i+1;
              int end=n-1;
              
              // Iterate Two Pointer
              while(start<end)
              {
                  int val=nums[start]+nums[end]+nums[i];
                  
            // If three values summation is equal to target then just return
                  if(val==target)
                      return target;
                  else
                  {
                    // If val<target then just point 'start' to it's next value
                      if(val<target)
                          start++;
                  else
                      // If val>target then just point 'end' to it's last value
                      end--;}
                  
        // Store value every time in result if you find a value more closer to it's target
                  if(diff>abs(val-target))
                  {  
                      diff=abs(val-target);
                      result=val;
                  }
              }
          }
        
       // Return Result
        return result;
    } 
};