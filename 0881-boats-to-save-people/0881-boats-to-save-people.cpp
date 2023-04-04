class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int i=0;
        int ans=0;
        int j=people.size()-1;
        while(i<=j){
            ans++;
            if(people[i]+people[j]<=limit){
       
                i++;
            }
            j--;
        }
        return ans;
        
    }
};