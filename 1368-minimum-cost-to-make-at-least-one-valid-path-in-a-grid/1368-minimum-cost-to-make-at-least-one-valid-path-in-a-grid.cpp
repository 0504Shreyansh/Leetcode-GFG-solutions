class Node {
public:
    int x, y, cost;
    Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {};
};

class Comp {
public:
    bool operator()(Node* a, Node* b) {
        return a->cost > b->cost;
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // similar to 0-1 bfs
        int n = grid.size(), m = grid[0].size();
        set<pair<int, int>> seen;
        priority_queue<Node*, vector<Node*>, Comp> pq;
        pq.push(new Node(0, 0, 0));
        int dirs[] = {0, -1, 0, 1, 0};
        while (pq.size()) {
            Node* cur = pq.top();
            pq.pop();
            int x = cur -> x;
            int y = cur -> y;
            int cost = cur -> cost;
            if (seen.count({x, y})) 
                continue;
            seen.insert({x, y});
            if (x == n - 1 && y == m - 1) 
                return cost;
            for (int k = 0; k < 4; k++) {
                int X = x + dirs[k], Y = y + dirs[k + 1];
                if (X >= 0 && X < n && Y >= 0 && Y < m) {
                    if (grid[x][y] == 1 && Y - y == 1) {
                        pq.push(new Node(X, Y, cost));
                    } else if (grid[x][y] == 2 && Y - y == -1) {
                        pq.push(new Node(X, Y, cost));
                    } else if (grid[x][y] == 3 && X - x == 1) {
                        pq.push(new Node(X, Y, cost));
                    } else if (grid[x][y] == 4 && X - x == -1) {
                        pq.push(new Node(X, Y, cost));
                    } else {
                        pq.push(new Node(X, Y, cost + 1));
                    }
                }
            }
        }
        return -1;
    }
};