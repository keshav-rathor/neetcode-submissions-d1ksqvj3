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
        // TreeNode* prev=NULL;
        // solver(root, prev,flag);
        return solver(root, LONG_MIN, LONG_MAX);
    }
    bool solver(TreeNode* root,long left,long right)
    {
        if(!root) return true;
        if(!(left<root->val && right>root->val)) return false;
        bool l=solver(root->left,left,root->val);
        bool r=solver(root->right,root->val,right);
        return l && r;
    }
};