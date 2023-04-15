class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            if(cur>0 and mp.find(-1*cur)!=mp.end()){
                ans=max(ans,cur);
            }
          
        }
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<"->"<<it->second<<endl;
        // }
        return ans;
    }
};