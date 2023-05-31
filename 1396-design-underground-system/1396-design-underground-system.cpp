class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkin;
    unordered_map<string,pair<double,int>> timings;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkin[id].first;
        int startTime = checkin[id].second;
        checkin.erase(id);
        // first time store
        if(timings.find(startStation + '+' + stationName) == timings.end()) {
            timings[startStation + '+' + stationName] = {t - startTime, 1};
        }
        // update the already calculated time
        else {
            auto cur = timings[startStation + '+' + stationName];
            double calTime = cur.first;
            int cnt = cur.second;
            calTime = (calTime * cnt + (t - startTime)) / (cnt + 1);
            timings[startStation + '+' + stationName] = {calTime, cnt + 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return timings[startStation + '+' + endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */