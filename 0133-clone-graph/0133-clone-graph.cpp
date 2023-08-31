/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> mp;
    Node* build(Node* node) {
        if (node == NULL) return NULL;
        if (mp.find(node) != mp.end()) return mp[node];
        mp[node] = new Node(node -> val, {});
        for (auto &it : node -> neighbors) {
            mp[node] -> neighbors.push_back(build(it));
        }
        return mp[node];
    }
public:
    Node* cloneGraph(Node* node) {
        return build(node);
    }
};