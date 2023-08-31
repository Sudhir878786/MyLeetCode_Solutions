class Solution {
public:
    vector<vector<int>>ans;
    void func(int n,int k,int ind,vector<int>&cur)
    {
        if(cur.size()>k){
            return;
        }
        if(cur.size()==k){
            ans.push_back(cur);
        }
        for(int i=ind;i<=n;i++){
            cur.push_back(i);
            func(n,k,i+1,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>cur;
        func(n,k,1,cur);
        return ans;
    }
};