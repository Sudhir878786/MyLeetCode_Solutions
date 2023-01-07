class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& costs) {
        int tgas=accumulate(gas.begin(),gas.end(),0);
        int tcost=accumulate(costs.begin(),costs.end(),0);
        if(tgas<tcost){
            return -1;
        }
        int sum=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-costs[i];
            if(sum<0){
                ans=i+1;
                sum=0;
            }
        }
        return ans;
    }
};