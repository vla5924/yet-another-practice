// https://leetcode.com/problems/balanced-binary-tree/

#include <cmath>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<TreeNode *, int> depths;
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        auto it = depths.find(root);
        if (it == depths.end()) {
            int d = max(1 + depth(root->left), 1 + depth(root->right));
            depths[root] = d;
            return d;
        }
        return it->second;
    }

  public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main() { return 0; }
