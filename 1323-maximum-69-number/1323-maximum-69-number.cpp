class Solution {
public:
    int maximum69Number (int num) {
        string ans= to_string(num);
        for(auto &it:ans){
            if(it=='6'){
                it='9';
                break;
            }
        }
        return stoi(ans);
    }
};