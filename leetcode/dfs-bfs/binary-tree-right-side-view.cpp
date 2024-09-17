// https://leetcode.com/problems/binary-tree-right-side-view/

#include <vector>

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
    void dfs(TreeNode *node, vector<int> &vals) {
        vals.push_back(node->val);
        if (node->right) {
            dfs(node->right, vals);
        } else if (node->left) {
            dfs(node->left, vals);
        }
    }

    void bfs(const vector<TreeNode *> &layer, vector<int> &vals) {
        if (layer.empty())
            return;
        vals.push_back(layer.back()->val);
        vector<TreeNode *> nextlayer;
        for (auto *node : layer) {
            if (node->left)
                nextlayer.push_back(node->left);
            if (node->right)
                nextlayer.push_back(node->right);
        }
        bfs(nextlayer, vals);
    }

  public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root)
            return {};
        vector<int> vals;
        bfs({root}, vals);
        return vals;
    }
};

int main() { return 0; }
