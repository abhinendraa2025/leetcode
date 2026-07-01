/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return postOrder(root, INT_MIN);
    }

private:
    int postOrder(TreeNode* root, int maxSoFar) {
        if (root == nullptr) return 0;   // base case: return 0, not void

        int newMax = std::max(maxSoFar, root->val);
        int left = postOrder(root->left, newMax);
        int right = postOrder(root->right, newMax);

        if (root->val >= maxSoFar) {
            return 1 + left + right;
        } else {
            return left + right;
        }
    }
};