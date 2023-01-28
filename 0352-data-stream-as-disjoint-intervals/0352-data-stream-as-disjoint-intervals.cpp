class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int first=*st.begin();
        int end=*st.begin();
        for(auto i=++st.begin();i!=st.end();i++){
            int val=*i;
            if(val-end==1){
                end=val;
            }
            else{
                ans.push_back({first,end});
                first=end=val;
            }
        }
        ans.push_back({first,end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */