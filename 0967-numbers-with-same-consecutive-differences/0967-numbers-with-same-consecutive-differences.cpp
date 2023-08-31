class Solution {
public:
    vector<int>ans;
    void func(int n,int k,int cur,int ind)
    {
        if(ind==n){
            ans.push_back(cur);
            return ;
        }
        
        int last=cur%10;
        for(int i=0;i<=9;i++){
            if(abs(i-last)==k){
                func(n,k,cur*10+i,ind+1);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            func(n,k,i,1);
        }
        return ans;
    }
};