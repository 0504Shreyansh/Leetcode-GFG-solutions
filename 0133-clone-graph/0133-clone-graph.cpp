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
    map<Node*, Node*> map;
    Node* create(Node* node) {
        if (node == NULL) return NULL;
        if (map.find(node) != map.end()) return map[node];
        map[node] = new Node(node->val, {});
        for (auto &it : node->neighbors) {
            map[node]->neighbors.push_back(create(it));
        }
        return map[node];
    } 
public:
    Node* cloneGraph(Node* node) {
        return create(node);
    }
};