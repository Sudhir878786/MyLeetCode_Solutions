class MyCalendarTwo {
public:
    map<int,int>mp;              // initialize a ordered map
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
   
        mp[start]++;      // +1 when we see start;
        mp[end]--;       //  -1 when we see end
        int sum=0;
        for(auto it:mp){
            sum+=it.second;   // store the sum 
            if(sum>=3){   
                mp[start]--;   // if cndition fails   
                mp[end]++;    // delete from map;
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */