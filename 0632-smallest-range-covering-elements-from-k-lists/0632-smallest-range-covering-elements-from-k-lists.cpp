class Node {
public: 
    int i, j, data;
    Node(int _i, int _j, int _data) : i(_i), j(_j), data(_data){};
};

class Comparator {
public:
    bool operator()(Node *a, Node *b) {
        return a -> data > b -> data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, Comparator> pq;
        int maxi = -1e6;
        int mini = 1e9;
        int diff = 1e9;
        int maximum = -1e6;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(new Node(i, 0, nums[i][0]));
            maxi = max(maxi, nums[i][0]);
        }      
        while(pq.size()) {
            Node* curr = pq.top();
            int i = curr -> i;
            int j = curr -> j;
            int data = curr -> data;
            pq.pop();
            if(maxi - data < diff) {
                mini = data;
                maximum = maxi;
                diff = maxi - data;
            }
            if(j + 1 >= nums[i].size()) {
                return {mini, maximum};
            } else {
                pq.push(new Node(i, j + 1, nums[i][j + 1]));
                maxi = max(maxi, nums[i][j + 1]);
            }
        }
        return {};
    }
};