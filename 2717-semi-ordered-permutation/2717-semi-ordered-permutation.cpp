class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int first, last;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == 1){
                first = i;
            }else if(nums[i] == nums.size()){
                last = i;
            }
        }
        // cout<<"first"<<first<<" and "<<last<<Endl;
        int answer = first + (nums.size() - 1 - last);
        if(first > last){
            answer -= 1;
            
        }
        return answer;
    }
};