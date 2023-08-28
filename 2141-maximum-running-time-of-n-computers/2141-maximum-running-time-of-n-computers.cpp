class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        sort(bat.rbegin(),bat.rend());
        long long sum=accumulate(bat.begin(),bat.end(),0ll),avg,ind=0;
      
        while(n>0 and bat[ind]>(avg=sum/n)){
            sum-=bat[ind++];
            n--;
            
        }
        return avg;
        
        
    }
};