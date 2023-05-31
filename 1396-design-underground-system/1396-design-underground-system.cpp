class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>info;
    unordered_map<string,pair<double,int>>avg;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        info[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string cur=info[id].first+" "+stationName;
        double time=abs(info[id].second-t);
        avg[cur].first+=time;
        avg[cur].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string cur=startStation+" "+endStation;
        return avg[cur].first/avg[cur].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */