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
    int ans=0;
    int goodNodes(TreeNode* root) {
        solver(root,INT_MIN);
        return ans;
        
    }
    void solver(TreeNode* root,int mx)
    {
        if(!root) return;
        if(root->val>=mx) ans++;

        mx=max(mx,root->val);
        solver(root->left,mx);
        solver(root->right,mx);
    }
};

