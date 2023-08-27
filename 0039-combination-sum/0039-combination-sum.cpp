class Solution {
public:
    vector<vector<int>>ans;
    vector<int>cur;
    void func(int ind,vector<int>&can,int tar)
    {
        if(ind==can.size()){
            if(tar==0){
                ans.push_back(cur);
            }
            return;
        }
        
        
        if(can[ind]<=tar){
            cur.push_back(can[ind]);
            func(ind,can,tar-can[ind]);
            cur.pop_back();
        }
        func(ind+1,can,tar);
        
    }
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        func(0,can,tar);
        return ans;
    }
};