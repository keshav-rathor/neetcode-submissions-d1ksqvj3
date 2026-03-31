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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solver(root,p,q);
    }
    TreeNode* solver(TreeNode* root,TreeNode* p,TreeNode* q )
    {
        if(!root) return root;
        if(root->val>p->val && q->val<root->val) return solver(root->left,p,q);
        if(root->val<p->val && q->val>root->val) return solver(root->right,p,q);
        return root;

    }
};
