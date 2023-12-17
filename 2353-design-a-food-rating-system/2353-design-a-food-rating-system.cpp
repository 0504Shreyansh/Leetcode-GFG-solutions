struct compare {
    bool operator()(auto &a, auto &b) const {
        if (a.first == b.first) return a.second < b.second;
        return (a.first > b.first);
    }
};

class FoodRatings {
private:
    map<string, multiset<pair<int, string>, compare>> CRF;
    map<string, int> FR;
    map<string, string> FC;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            int rating = ratings[i];
            string cuisine = cuisines[i];
            CRF[cuisine].insert({rating, food});
            FR[food] = rating;
            FC[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = FR[food];
        FR[food] = newRating;
        string cuisine = FC[food];
        CRF[cuisine].erase({oldRating, food});
        CRF[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return begin(CRF[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */