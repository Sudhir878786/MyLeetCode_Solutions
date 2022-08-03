class MyCalendar {
public:
    vector<vector<int>>a;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &i:a)
            if(i[0]<end and start<i[1])
                return false;
        vector<int>ans;
        ans.emplace_back(start);
        ans.emplace_back(end);
        a.emplace_back(ans);
        return true;
    }
};
