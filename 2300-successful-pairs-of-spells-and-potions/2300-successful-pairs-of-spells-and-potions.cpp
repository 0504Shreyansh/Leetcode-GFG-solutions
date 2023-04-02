class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = potions.size();
        int m = spells.size();
        unordered_map<int,set<int>> indices;
        vector<int> res(spells);
        
        // Step 1 - Store the indexes of the cur spell to keep a track
        for(int i = 0; i < m; i++) 
            indices[spells[i]].insert(i);
        
        // Step 2 - sort both the arrays
        /* Sorting bcoz if some potions[i] is found matching with the 
           the cur spell spell[i], then it is going to match with rest 
           of the greater potions[i], so use binary search.*/
        sort(spells.begin(),spells.end());
        sort(potions.begin(),potions.end());

        for(auto spell : spells) {
            long long cur = spell;
            long long minPoints = 0;
            // Step 3 - Find out minimum points required
            // If the success is divisble by spell[i], search for success/spell[i]
            if(success % cur == 0)
                minPoints = success / cur;
            // Else search for the upper bound success/spell[i]+1
            else 
                minPoints = success / cur + 1;
            // Step 4 - Find out the lower bound of minPoints
            // Find out the probable occurence of minPoints
            // potions[i] that are greater than the cur potion
            // can also be included in the answer
            int lb = lower_bound(potions.begin(),potions.end(),minPoints) - potions.begin();
            // Step 5 - Evaluate the answer and store in the indexes.
            // So, the count of the selected potions is (n - lb)
            // Store the answer in all the indexes of the current spell
            for(auto ind : indices[cur])
                res[ind] = n - lb;
            indices[cur].clear();
        }
        return res;
    }
};