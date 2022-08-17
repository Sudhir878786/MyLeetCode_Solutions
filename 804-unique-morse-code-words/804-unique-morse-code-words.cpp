class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
         vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>ans;
        for(auto it:words){
            string s="";
            for(auto x:it){
                s+=morse_code[x-'a'];
            }
            ans.insert(s);
        }
        return ans.size();
    }
};