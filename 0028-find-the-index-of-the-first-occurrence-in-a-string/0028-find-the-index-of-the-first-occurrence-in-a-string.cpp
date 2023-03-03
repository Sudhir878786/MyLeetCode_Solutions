class Solution {
public:
    int strStr(string hy, string needle) {
        if(needle=="")return 0;
        int i=0,j=0;
        while(i<hy.size() and j<needle.size()){
            if(hy[i]==needle[j]){
                i++;j++;
                if(j==needle.size()){
                    return i-needle.size();
                }
            }
            else{
                i=i-j+1;
                j=0;
            }
        }
        return -1;
    }
};