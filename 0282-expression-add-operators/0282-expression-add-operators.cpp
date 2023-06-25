class Solution {
public:
    
    vector<string>ans;
    void func(string&num,int tar,long long start,string res, long long sum,long long prev)
    {
        if(start==num.size()){
            if(sum == tar){
                ans.push_back(res);
            }
            return;
        }
        for(long long i=start;i<num.size();i++){
            if(i>start and num[start]=='0'){
                break;
            }
            string cur=num.substr(start,i+1-start);
            long long temp=stoll(cur);
            // cout<<temp<<endl;
            if(start==0){
                func(num,tar,i+1,res+to_string(temp),temp,temp);
            }else{
                func(num,tar,i+1,res+'*'+to_string(temp),sum-prev+(temp*prev),temp*prev);
                func(num,tar,i+1,res+'+'+to_string(temp),sum+temp,temp);
                func(num,tar,i+1,res+'-'+to_string(temp),sum-temp,-1*temp);
                
            }
        }
        return ;
    }
    vector<string> addOperators(string num, int target) {
         func(num,target,0,"",0,0);
        return ans;
    }
};