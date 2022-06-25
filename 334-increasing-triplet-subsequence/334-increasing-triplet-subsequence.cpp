class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size();
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(auto i:a){
            if(i<min1)min1=i;
            else if(i<min2 && min1<i)min2=i;
            else if(i>min2)return 1;
        }
        return 0;
        
    }
};