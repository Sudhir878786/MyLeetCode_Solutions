class Solution {
public:
    bool func(vector<vector<char>>& board, string word,int i,int j,int k,int n,int m)
    {
        if(k==word.size()){
            return true;
        }
        if(i>=n || j>=m || i<0 || j<0 || board[i][j]!=word[k]){
            return false;
        }
        
        char ch= board[i][j];
        board[i][j]=' ';
        bool ans= func(board,word,i+1,j,k+1,n,m)||
                  func(board,word,i-1,j,k+1,n,m)||
                  func(board,word,i,j+1,k+1,n,m)||
                  func(board,word,i,j-1,k+1,n,m);
        board[i][j]=ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();  
        // we will frst find the first word[0] in the grid and then start dfs
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && func(board,word,i,j,0,n,m)){
                    return true;
                }
                
            }
        }
        return false;
        
    }
};