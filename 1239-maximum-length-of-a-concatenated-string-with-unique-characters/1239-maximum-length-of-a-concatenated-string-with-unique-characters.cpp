class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> masks(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            bool ok = true;
            int mask = 0;
            for (char &c : arr[i]) {
                if (mask & (1 << (c - 'a'))) {
                    ok = false;
                    break;
                }
                mask |= (1 << (c - 'a'));
            }
            if (ok) {
                masks[i] = mask;
            }
        }

        int ans = 0;
        for (int i = 0; i < 1 << n; i++) {
        	int newMask = 0;
        	for (int b = 0; b < n; b++) {
        		if (i >> b & 1) {
        			if (masks[b] == INT_MAX) {
                        newMask = 0;
        				break;
        			}
        			if ((newMask ^ masks[b]) == newMask + masks[b]) {
        				newMask |= masks[b];
        			}
        		}
        	}
        	ans = max(ans, __builtin_popcount(newMask));
        }

        return ans;
    }
};