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
    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(!root) return false;
        if(root->val==subRoot->val && sub(root,subRoot))
        {
            return true;
        }

        return dfs(root->left,subRoot) || dfs(root->right,subRoot);
    }
    bool sub(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot) return true;
        if(!root || !subRoot || root->val!=subRoot->val) return false;


        bool left=sub(root->left,subRoot->left);
        bool right=sub(root->right,subRoot->right);

        return left && right;
    }
};
