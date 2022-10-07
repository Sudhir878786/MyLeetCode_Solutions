class MyCalendar {
public:
    vector<vector<int>>ans;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &x:ans){
            int a=x[0];
            int b=x[1];
            if(a<end and b>start){
                return false;
            }
            
        }
        vector<int>t;
        t.push_back(start);
        t.push_back(end);
        ans.push_back(t);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */