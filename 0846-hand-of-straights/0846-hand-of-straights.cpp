class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> m;
        for(auto &it : hand) {
            m[it]++;
        }
        sort(begin(hand),end(hand));
        for(int i = 0; i < hand.size(); i++) {
            int k = groupSize;
            int num = hand[i];
            while(k && m.find(num) != m.end()) {
                if(--m[num] == 0) m.erase(num);
                num++;
                k--;
            }
            if(k != groupSize) {
                if(k != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};