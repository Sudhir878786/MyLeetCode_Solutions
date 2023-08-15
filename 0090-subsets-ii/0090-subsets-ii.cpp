class Solution {
public:
     vector<vector<int>> ans;
    set<vector<int>>st;
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            st.insert(temp);
            return;
        }
        
        sub(nums, i+1, temp);
        temp.push_back(nums[i]);
        sub(nums, i+1, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
        for(auto v:st){
            ans.push_back(v);
        }
        return ans;
    }
};

