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
    // void solutionn(TreeNode* root, vector<int> &vect)
    // {
    //     if(root == NULL)
    //     return;
    //     vect.push_back(root->val);
    //     solutionn(root->left,vect);
    //     solutionn(root->right,vect);    
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> vect;
    //     solutionn(root, vect);
    //     return vect;    
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vect;
        if(root==NULL)
            return vect;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            vect.push_back(root->val);
            if(root->right != NULL)
                st.push(root->right);
            if(root->left != NULL)
                st.push(root->left);                
        }
        return vect;    
    }
};