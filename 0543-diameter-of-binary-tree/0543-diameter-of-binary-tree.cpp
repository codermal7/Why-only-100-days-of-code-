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
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        height(root,diam);
        return diam;
    }
    int height(TreeNode* root, int& diam){
        if(root==NULL)
        return 0;
        int lh=height(root->left, diam);
        int rh=height(root->right, diam);
        diam = max(diam,lh+rh);

        return 1+max(lh,rh);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();