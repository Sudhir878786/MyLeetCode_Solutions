class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(auto it:moves){
            if(it=='U')j++;
            else if(it=='D')j--;
            else if(it=='R')i--;
            else i++;
        }
        return i==0 and j==0;
    }
};