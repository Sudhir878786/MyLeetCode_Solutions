class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
         
        int n=stones.size();
        while(n>1)
        {
        sort(stones.begin(),stones.end());
        int a=stones[n-1];
        int b=stones[n-2];
        stones.pop_back();
        stones.pop_back();
        if(a!=b)
        stones.push_back(abs(b-a));
        n=stones.size();
        }
        if(n==1)
            return stones[0];
        else
            return 0;
         
    }
};