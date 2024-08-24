// https://leetcode.com/problems/clone-graph/

#include <unordered_map>
#include <vector>

using namespace std;

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    Node *cloneNode(Node *node, unordered_map<Node *, Node *> &cloned) {
        if (node == nullptr)
            return nullptr;
        auto it = cloned.find(node);
        if (it != cloned.end())
            return it->second;
        Node *clonedNode = (cloned[node] = new Node(node->val));
        vector<Node *> neighbors;
        clonedNode->neighbors.reserve(node->neighbors.size());
        for (Node *n : node->neighbors)
            clonedNode->neighbors.push_back(cloneNode(n, cloned));
        return clonedNode;
    }

  public:
    Node *cloneGraph(Node *node) {
        unordered_map<Node *, Node *> cloned;
        return cloneNode(node, cloned);
    }
};

int main() { return 0; }
