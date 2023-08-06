class Node {
public:
    int x, y, cost;
    Node(int _x, int _y, int _cost) {
        x = _x;
        y = _y;
        cost = _cost;
    }
};

class comp {
public:
    bool operator()(Node* &a, Node* &b) {
        return a->cost > b->cost;
    }
};

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        set<pair<int, int>> seen;
        priority_queue<Node*, vector<Node*>, comp> pq;
        pq.push(new Node(start[0], start[1], 0));
        while (pq.size()) {
            Node* cur = pq.top();
            pq.pop();
            int x = cur->x, y = cur->y, cost = cur->cost;
            if (seen.count({x, y})) continue;
            seen.insert({x, y});
            if (x == target[0] && y == target[1]) return cost;
            pq.push(new Node(target[0], target[1], cost + abs(target[0] - x) + abs(target[1] - y)));
            for (auto &it : specialRoads) {
                if (!seen.count({it[2], it[3]})) {
                    pq.push(new Node(it[2], it[3], cost + it[4] + abs(it[0] - x) + abs(it[1] - y)));
                }
            }
        }
        return -1;
    }
};