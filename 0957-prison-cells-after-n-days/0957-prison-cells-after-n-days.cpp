class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int>ans=cells;
        cells[0]=cells[7]=0;
        if(n%14==0){
            n=14;
        }else n=n%14;
    
        for(int i=0;i<n;i++){
            for(int j=1;j<7;j++ ){
                cells[j]= (ans[j-1]==ans[j+1]);
            }
            ans=cells;
        }
        return ans;
    }
};