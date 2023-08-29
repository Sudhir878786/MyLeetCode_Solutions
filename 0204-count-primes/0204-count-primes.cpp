class Solution {
public:
    /*
    n= 15
    using sieve 
    mark true from 2->15  
    2 3 4 5 6 7 8 9 10 11 12 13 14 15
    if(2 is true ) then start from i*i ie 2*2(4) and start marking false 
    2 3 4(f),5,6(f),7,8(f),9,10(f),11,12(f),13,14(f),15
    agian start from 3 if is true then repeat the same procedure
    */ 
    // TC O(nlog(log(n)));
    
    int countPrimes(int n) {
        if(n<=1){
            return 0;
        }
        vector<bool>mark(n,true);
        mark[0]=false;
        mark[1]=false;
        for(int i=2;i*i<n;i++){
            if(mark[i]==true){
                for(int j=i*i;j<n;j+=i){
                    mark[j]=false;
                }
            }
        }
        return count(mark.begin(),mark.end(),true);
    }
};