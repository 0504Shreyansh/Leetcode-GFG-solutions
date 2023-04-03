class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int i = 0, j = people.size()-1;
        int ans = 0;
        while(i < j) {
            // Weight of 2 people exceeds, so just take the heavy person
            if(people[i] + people[j] > limit)
                ans++, j--;
            // Else take both the person
            else 
                ans++, i++, j--;
        }
        // Only 1 person remains, take 1 boat
        ans += (i==j);
        return ans;
    }
};