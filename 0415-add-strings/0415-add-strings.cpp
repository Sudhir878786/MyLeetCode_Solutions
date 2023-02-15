class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int car=0;
        while(i>=0 || j>=0 || car){
            int sum=0;

            if(i>=0){
                sum+=(num1[i]-'0');
                i--;
            }
            if(j>=0){
                sum+=(num2[j]-'0');
                j--;
            }
            sum+=car;
            car=sum/10;
            sum=sum%10;
            ans=ans+to_string(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};