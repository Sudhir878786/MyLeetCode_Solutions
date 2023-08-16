class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        list<int>cur;
        int i=0,j=0;
        while(j<nums.size()){
            while(cur.size()>0 and cur.back()<nums[j]){
                cur.pop_back();
            }
            cur.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(cur.front());
                if(nums[i]==cur.front()){
                    cur.pop_front();
                }
                i++;
            j++;
            }
            
        }
        return ans;
    }
};