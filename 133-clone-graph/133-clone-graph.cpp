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
    Node* dfs(Node* node, map<int, Node*>& m) {
        if (!node)
            return nullptr;
        if (m.find(node->val) != m.end())
            return m[node->val];
        Node* newNode = new Node();
        newNode->val = node->val;
        m[node->val] = newNode;
        for (auto neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor, m));
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> m;
        return dfs(node, m);
    }
};