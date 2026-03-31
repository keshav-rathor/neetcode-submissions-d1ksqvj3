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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
    bool dfs(TreeNode* root, TreeNode* sub)
    {
        if(!root ) return false;
        if(root->val== sub->val && same(root,sub)) return true;

        bool left=dfs(root->left,sub);
        bool right=dfs(root->right,sub);
        return left || right;

    }
    bool same(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        bool left=same(p->left, q->left);
        bool right=same(p->right, q->right);
        return left && right;

    }
};
