// https://leetcode.com/problems/symmetric-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isSymmetricNode(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (p && q) {
            return p->val == q->val && isSymmetricNode(p->left, q->right) && isSymmetricNode(p->right, q->left);
        }
        return false;
    }

  public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetricNode(root->left, root->right);
    }
};

int main() { return 0; }
