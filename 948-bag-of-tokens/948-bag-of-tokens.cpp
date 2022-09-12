class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0;
        int score=0;
        int i=0;
        int j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            
            while(i<=j and tokens[i]<=power){
                score++;
                
                power-=tokens[i];
                i++;
            }
            if(i>=j || score<=0){
                break;
            }
            score-=1;
            power+=tokens[j];
            j--;
            
                
            
        }
        return score;
    }
};