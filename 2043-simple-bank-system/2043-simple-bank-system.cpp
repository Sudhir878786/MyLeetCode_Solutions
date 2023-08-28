class Bank {
public:
    vector<long long >temp;
    int n;
    Bank(vector<long long>& balance) {
        temp=balance;
        n=temp.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<=temp.size() and account2<=temp.size() and account1>0 and account2>0 and temp[account1-1]>=money){
            temp[account1-1]-=money;
            temp[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>temp.size() || account<0){
            return false;
        }
        temp[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=temp.size() and account >0 and temp[account-1]>=money)
        {
            temp[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */