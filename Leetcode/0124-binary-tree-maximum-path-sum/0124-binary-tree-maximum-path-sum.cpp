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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxP(root, maxi);
        return maxi;
    }

    int maxP(TreeNode* root, int & maxi) {
        if(root==NULL) return 0;
        int lh= max(0,maxP(root->left, maxi));
        int rh= max(0,maxP(root->right, maxi));
        maxi=max(maxi,(lh+rh+root->val));
        return root->val+max(lh,rh);
    }
};