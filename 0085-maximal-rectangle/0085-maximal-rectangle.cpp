class Solution {
public:
    int func(vector<int>&histo)
    {
        int n=histo.size();
        stack<int>st;
        int area=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n ||histo[st.top()]>histo[i])){
                int height=histo[st.top()];
                st.pop();
                int width=0;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                area=max(area,width*height);
                
            }
            st.push(i);
        }
        return area;
         
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int ans=0;
        int m=matrix[0].size();
        vector<int>his(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    his[j]++;
                }else{
                    his[j]=0;
                }
                
            }
            int area=func(his);
            ans=max(ans,area);
        }
        // for(int i=0;i<m;i++){
        //     cout<<his[i]<<" ";
        // }
        // cout<<endl;
        
        return ans;
    }
};