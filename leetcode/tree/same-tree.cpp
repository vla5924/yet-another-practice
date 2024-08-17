// https://leetcode.com/problems/same-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isSameNode(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (p && q) {
            return p->val == q->val && isSameNode(p->left, q->left) && isSameNode(p->right, q->right);
        }
        return false;
    }

  public:
    bool isSameTree(TreeNode *p, TreeNode *q) { return isSameNode(p, q); }
};

int main() { return 0; }
