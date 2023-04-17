class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int ext) {
          vector<bool>ans;
        int maxx=*max_element(begin(can),end(can));
        for(auto it:can){
            
            ans.push_back(ext+it >=maxx);
        }
        return ans;
    }
};