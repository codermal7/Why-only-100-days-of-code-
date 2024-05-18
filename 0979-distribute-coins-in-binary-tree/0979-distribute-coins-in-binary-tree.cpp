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
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
private:
    int moves;
    int dfs(TreeNode* current) {
        if (!current) 
            return 0;

        int leftCoins = dfs(current->left);
        int rightCoins = dfs(current->right);

        moves += abs(leftCoins) + abs(rightCoins);

        return (current->val - 1) + leftCoins + rightCoins;
    }
};