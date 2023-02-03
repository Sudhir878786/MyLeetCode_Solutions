class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string> zigzag(numRows,"");
        int n=s.size(),direction=1,i=0,line=0;
        string ans="";
        while(i<n){
            if(line==0 && direction==-1){
                direction=1;
            }
            if(line==numRows-1 && direction==1){
                direction=-1;
            }
            zigzag[line]+=s[i];
            i++;
            line+=direction;
        }
        for(int i=0;i<numRows;i++){
            if(zigzag[i]!="")ans+=zigzag[i];
        }
        return ans;
    }
};