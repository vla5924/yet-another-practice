// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *curP = root;
        TreeNode *curQ = root;
        TreeNode *anc = root;
        // curP and curQ cannot be leaves
        while (curP && curQ && curP == curQ) {
            anc = curP;
            if (curP->val < p->val)
                curP = curP->right;
            else if (curP->val > p->val)
                curP = curP->left;
            if (curQ->val < q->val)
                curQ = curQ->right;
            else if (curQ->val > q->val)
                curQ = curQ->left;
        }
        return anc;
    }
};

int main() { return 0; }
