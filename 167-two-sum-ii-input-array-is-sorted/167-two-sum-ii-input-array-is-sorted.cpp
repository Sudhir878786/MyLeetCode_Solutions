class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        int j=ar.size()-1;
        int i=0;
        while(i<j){
            int cur = ar[i]+ar[j];
            if(cur == target){
                return {i+1,j+1};
            }
            if(cur<target) i++;
            else j--;
        }
    return {};
    }
};