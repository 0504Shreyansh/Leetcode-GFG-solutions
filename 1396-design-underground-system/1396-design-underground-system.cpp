class UndergroundSystem {
    private:
        unordered_map<int,pair<string,int>> checkin; 
        unordered_map<string,pair<double,int>> checkout; 
    public:
        UndergroundSystem() {

        }
        void checkIn(int id, string stationName, int t) {
            checkin[id] = {stationName,t};
        }
        void checkOut(int id, string stationName, int t) {
            //New string(Source-Destination)
            string dest = checkin[id].first + '-' + stationName;
            //Total time storage
            checkout[dest].first += t - checkin[id].second;
            //Coutn storage
            checkout[dest].second++;
            checkin.erase(id);
        }
        double getAverageTime(string startStation, string endStation) {
            //Source-Destination
            string sourceToDestination = (startStation+'-'+endStation);
            return (checkout[sourceToDestination].first)/(checkout[sourceToDestination].second);
        }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */