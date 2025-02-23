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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int len = pre.size();
        return reconstruct(pre, 0, len - 1, post, 0, len - 1);
    }

private:
    TreeNode* reconstruct(vector<int>& pre, int preStart, int preEnd,
                          vector<int>& post, int postStart, int postEnd) {
        if (preStart > preEnd) 
            return nullptr;

        TreeNode* node = new TreeNode(pre[preStart]);

        if (preStart == preEnd) 
            return node;

        int leftRootValue = pre[preStart + 1];
        int postIndex = postStart;
        
        while (post[postIndex] != leftRootValue)
            postIndex++;

        int leftSubtreeSize = postIndex - postStart + 1;

        node->left = reconstruct(pre, preStart + 1, preStart + leftSubtreeSize, post, postStart, postIndex);
        node->right = reconstruct(pre, preStart + leftSubtreeSize + 1, preEnd, post, postIndex + 1, postEnd - 1);

        return node;
    }
};
