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
    // O(n) code
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


    // O(n^2) Code
    // int diameterOfBinaryTree(TreeNode* root) {
    //     int diam = 0;
    //     height(root, diam);
    //     return diam;
    // }
    // int height(TreeNode* root, int& diam){
    //     if(root==NULL)
    //     return 0;
    //     int lh=height(root->left, diam);
    //     int rh=height(root->right, diam);
    //     diam = max(diam,lh+rh);
    //     height(root->left, diam);
    //     height(root->right, diam);
    //     return 1+max(lh,rh);
    // }
};