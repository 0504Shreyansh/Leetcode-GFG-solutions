class SeatManager {
private:
    set<int> available;
public:
    SeatManager(int n) {
        for (int seat = 1; seat <= n; seat++)
            available.insert(seat);
    }
    
    int reserve() {
        int seat = *available.begin();
        available.erase(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        available.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */