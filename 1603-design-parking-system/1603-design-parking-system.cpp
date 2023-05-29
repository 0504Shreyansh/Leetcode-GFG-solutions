class ParkingSystem {
public:
    int _big;
    int _medium;
    int _small;
    ParkingSystem(int big, int medium, int small) {
        _big = big;
        _medium = medium;
        _small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(_big > 0) {
                _big--;
                return true;
            }
            return false;
        }
        else if(carType == 2) {
            if(_medium > 0) {
                _medium--;
                return true;
            }
            return false;
        }
        else {
            if(_small > 0) {
                _small--;
                return true;
            }
            return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */