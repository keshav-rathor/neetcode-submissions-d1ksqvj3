class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solver(root, p, q);
    }

    TreeNode* solver(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if(p->val <root->val && q->val<root->val) return solver(root->left,p,q);

        if(p->val >root->val && q->val>root->val) return solver(root->right,p,q);
        return root;
    }
};
