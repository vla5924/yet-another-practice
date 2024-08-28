// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iterator>
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
    TreeNode *subtree(vector<int> &preorder, int &rootValueIndex, vector<int>::iterator inorderBegin,
                      vector<int>::iterator inorderEnd) {
        if (rootValueIndex >= preorder.size())
            return nullptr;
        int rootValue = preorder[rootValueIndex];
        // values are unique, so inorder search can be memoized
        // though this is not necessary here
        for (auto it = inorderBegin; it < inorderEnd; ++it)
            if (*it == rootValue) {
                TreeNode *root = new TreeNode(rootValue);
                // inorder of left subtree has >0 nodes
                if (it != inorderBegin) {
                    rootValueIndex += 1;
                    root->left = subtree(preorder, rootValueIndex, inorderBegin, it);
                }
                // inorder of right subtree has >0 nodes
                if (it != prev(inorderEnd)) {
                    rootValueIndex += 1;
                    root->right = subtree(preorder, rootValueIndex, next(it), inorderEnd);
                }
                return root;
            }
        return nullptr;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int rootValueIndex = 0;
        return subtree(preorder, rootValueIndex, inorder.begin(), inorder.end());
    }
};

int main() { return 0; }
