class Solution {
public:
    int moves = 0;

    int postorder(TreeNode* node) {
        if (!node) return 0;

        // 1. Visit LEFT subtree first
        int leftExcess = postorder(node->left);

        // 2. Visit RIGHT subtree next
        int rightExcess = postorder(node->right);

        // 3. Process current NODE last (this is the "post" step)
        moves += abs(leftExcess) + abs(rightExcess);

        // Pass this subtree's net excess up to the parent
        return node->val + leftExcess + rightExcess - 1;
    }

    int distributeCoins(TreeNode* root) {
        moves = 0;
        postorder(root);
        return moves;
    }
};