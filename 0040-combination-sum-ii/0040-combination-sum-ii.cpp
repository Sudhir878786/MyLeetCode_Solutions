class Solution {
public:
    
    vector<vector<int>> ans;
    set<vector<int>> s;
    void dfs(int idx,vector<int> arr,int target,int sum,vector<int> temp)
    {
        if(s.count(temp))
            return;
        if(idx>=arr.size() || target<=sum)
        {
            if(target==sum and !s.count(temp))
            {
                s.insert(temp);
                ans.push_back(temp);
            }
            return ;
        }

        
        if(sum<target)
        {
            temp.push_back(arr[idx]);
            dfs(idx+1,arr,target,sum+arr[idx],temp);
            temp.pop_back();
        }
        int i = idx;
        while(i<arr.size() and arr[i]==arr[idx])
            i++;
        dfs(i,arr,target,sum,temp);
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target,0,{});
        return ans;
    }
};