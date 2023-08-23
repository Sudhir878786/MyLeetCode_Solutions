class Solution {
public:
    int minOperations(vector<int>& nums) {
         //length of the initial array
        int len=nums.size();
        
        //remove duplicate elements and sort them
        set<int>S;
        for(auto &x:nums)
            S.insert(x);
        
        vector<int>temp;
        for(auto &x:S)
            temp.push_back(x);
        int ans=INT_MIN;
       queue<int>q;
        for(int i=0;i<temp.size();i++){
            q.push(temp[i]);
            if((q.back()-q.front())>nums.size()-1){
                q.pop();
            }
            ans=max(ans,(int)q.size());
            
        }
        return nums.size()-ans;
       
    
    }
};