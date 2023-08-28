class Solution {
public:
    vector<vector<string>>ans;
    bool safe(int r,int c,vector<string>&cur,int n)
    {
        for(int i=0;i<=r;i++){
            if(cur[i][c]=='Q'){
                return false;  // check in the column
            }
        }
        int row=r;
        int col=c;
        while(row>=0 and col>=0){
            if(cur[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=r;
        col=c;
        while(row>=0 and col<n){
            if(cur[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    void func(int ind,int n,vector<string>&cur)
    {
        if(ind==cur.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(ind,i,cur,n))
            {
                cur[ind][i]='Q';
                func(ind+1,n,cur);
                cur[ind][i]='.';  // bactrack 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>cur;
        string s(n,'.');
        for(int i=0;i<n;i++){
            cur.push_back(s);
        }
        func(0,n,cur);
        return ans;
    }
};