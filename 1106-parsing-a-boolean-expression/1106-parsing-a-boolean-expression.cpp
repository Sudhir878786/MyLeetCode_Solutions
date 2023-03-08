class Solution {
public:
    bool f_not( string& s,int& i){
        i+=2;
        auto ret = f(s,i);
        i++;
        return !ret;
    }
    
    bool f_and( string& s,int& i){
        i+=2;
        bool ret = true;
        ret &= f(s,i);
        while(s[i]!=')'){
            i++;
            ret &= f(s,i);
        }
        i++;
        return ret;
    }
    
    bool f_or( string& s,int& i){
        i+=2;
        bool ret = false;
        ret |= f(s,i);
        while(s[i]!=')'){
            i++;
            ret |= f(s,i);
        }
        i++;
        return ret;
    }
    
    bool f( string& s, int& i){
        if(s[i] == 't'){
            i++;
            return true;
        } else if(s[i] == 'f'){
            i++;
            return false;
        } else if(s[i] == '!'){
            return f_not(s,i);
        } else if(s[i] == '&'){
            return f_and(s,i);
        } return f_or(s,i);
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return f(expression,i);
    }
};