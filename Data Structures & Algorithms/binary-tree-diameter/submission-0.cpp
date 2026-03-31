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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        solver(root,ans);
        return ans;
    }
    int solver(TreeNode* root,int &ans)
    {
        if(!root) return 0;

        int left=solver(root->left,ans);
        int right=solver(root->right,ans);
        ans=max(ans,left+right);
        return 1+max(left,right);
    }
};
