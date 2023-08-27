class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void func(int ind,vector<int>&nums,vector<int>cur)
    {
        if(ind==nums.size()){
            st.insert(cur);
            return;
        }
        func(ind+1,nums,cur);
        cur.push_back(nums[ind]);
        func(ind+1,nums,cur);
        cur.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>cur;
        func(0,nums,cur);
        for(auto v:st){
            ans.push_back(v);
        }
        return ans;
    }
};