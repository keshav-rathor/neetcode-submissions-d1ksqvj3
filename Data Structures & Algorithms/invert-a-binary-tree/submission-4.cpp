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
    TreeNode* invertTree(TreeNode* root) {
        return solver(root);
    }
    TreeNode* solver(TreeNode* root)
    {
        if(!root) return root;

        TreeNode* left=solver(root->left);
        TreeNode* right=solver(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};
