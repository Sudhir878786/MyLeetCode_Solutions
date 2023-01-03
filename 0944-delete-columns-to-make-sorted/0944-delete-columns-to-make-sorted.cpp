class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            bool s=1;
            for(int j=1;j<n;j++){
                if(strs[j][i]<strs[j-1][i]){
                    s=0;
                    break;
                }
            }
            if(!s){
                count++;
            }
        }
        return count;
        
    }
};