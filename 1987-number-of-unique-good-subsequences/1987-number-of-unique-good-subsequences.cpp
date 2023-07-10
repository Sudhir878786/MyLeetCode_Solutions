class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int c1=0,c2=0;
        bool b =false;
        for(auto it:binary)
        {
            if(it=='1'){
                c1=(c1+c2+1)%1000000007;
            }else{
                b=1;
                c2=(c1+c2)%1000000007;
            }
        }
        return (c1+c2+b)%1000000007;
    }
};