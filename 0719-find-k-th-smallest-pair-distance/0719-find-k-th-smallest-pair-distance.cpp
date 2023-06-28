class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // vector<int>count(1000000,0);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         count[abs(nums[i]-nums[j])]++;
        //     }
        // }
        // for(int i=0;i<1000000;i++){
        //     if(count[i]>=k){
        //         return i;
        //     }
        //     k-=count[i];
        // }
        // return 0;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int end = nums[n-1]-nums[0];
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            int count = 0, s=0,e=0;
            
            while(e<n){
                while(nums[e]-nums[s] > mid and s<n) s++;
                count += (e-s);
                e++;
            }
            if(count >= k) end = mid-1;
            else start = mid+1;
        }
        
        return start;
        
    }
};