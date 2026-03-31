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
    bool isValidBST(TreeNode* root) {
        int flag=1;
        TreeNode* prev=NULL;
        solver(root, prev,flag);
        return flag;
    }
    void solver(TreeNode* root,TreeNode* &prev,int &flag)
    {
        if(!root) return;
        solver(root->left,prev,flag);
        if(prev!=NULL && prev->val>=root->val)
        {
            flag=0;
            return;
        }
        prev=root;
        solver(root->right,prev,flag);
    }
};