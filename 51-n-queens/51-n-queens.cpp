class Solution {
    vector<vector<string>>ans;

public:
    bool safe(int r,int c,vector<string>&v,int n)
    {
        for(int i=0;i<=r;i++){
            if(v[i][c]=='Q')return false;
        }
        int row=r;
        int col=c;
        while(row>=0 and col >=0)
        {
            if(v[row][col]=='Q'){
                return false ;
            }
            row--;
            col--;
            
        }
        row=r;col=c;
        while(row>=0 and col<n){
            if(v[row][col]=='Q') return false;
            row--;
            col++;
        }
        return true ;
    }
    
    
    void helper(int r, vector<string>&v,int n){
        if(r==n){
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<n;i++){
            if(safe(r,i,v,n)){
                v[r][i]='Q';
                helper(r+1,v,n);
                v[r][i]='.';
            }
           
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v;
        string s(n,'.');
        for(int i=0;i<n;i++){
            v.push_back(s);
        }
        helper(0,v,n);
        return ans ;
        
    }
};