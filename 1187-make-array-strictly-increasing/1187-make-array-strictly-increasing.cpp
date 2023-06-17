class Solution {
public:
    // dp[index][prevEle]
    map<pair<int,int>, int> dp;
    int minOperations(int i, vector<int>& arr1, vector<int>& arr2) {
        if(i >= arr1.size()) {
            return 0;
        }

        if(dp.find({i, (i == 0) ? -1 : arr1[i - 1]}) != dp.end()) {
            return dp[{i, (i == 0) ? -1 : arr1[i - 1]}];
        }

        int minOp = 1e9;
        
        if(i == 0) {
            if(arr1[0] > arr2[0]) {
                int prevNum = arr1[0];
                arr1[0] = arr2[0];
                int replace = 1 + minOperations(i + 1, arr1, arr2);
                minOp = min(minOp, replace);
                arr1[0] = prevNum;
            }   
            minOp = min(minOp, minOperations(i + 1, arr1, arr2));
        }
    
        // skip + replace
        else if(arr1[i - 1] < arr1[i]) {
            int index = upper_bound(begin(arr2),end(arr2),arr1[i - 1]) - begin(arr2);
            if(index >= 0 && index < arr2.size() && arr2[index] > arr1[i - 1]) {
                int prevNum = arr1[i];
                arr1[i] = arr2[index];
                int replace = 1 + minOperations(i + 1, arr1, arr2);
                arr1[i] = prevNum;
                minOp = min(minOp, replace);
            }
            
            minOp = min(minOp, minOperations(i + 1, arr1, arr2));
        }

        // replace
        else {
            int index = upper_bound(begin(arr2),end(arr2),arr1[i - 1]) - begin(arr2);
            if(index >= 0 && index < arr2.size() && arr2[index] > arr1[i - 1]) {
                int prevNum = arr1[i];
                arr1[i] = arr2[index];
                int replace = 1 + minOperations(i + 1, arr1, arr2);
                arr1[i] = prevNum;
                minOp = min(minOp, replace);
            }
        }

        return dp[{i, (i == 0) ? -1 : arr1[i - 1]}] = minOp;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        int ans = minOperations(0, arr1, arr2);
        dp.clear();
        return (ans > arr1.size()) ? -1 : ans;
    }
};