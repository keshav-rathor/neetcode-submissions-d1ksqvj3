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
    int maxDepth(TreeNode* root) {
        int ans=0;
        return solver(root,0);
        
    }
    int solver(TreeNode* root,int height)
    {
        if(!root)
        {
            return 0;
        }


        // height++;
        int left=1+solver(root->left,height);
        int right=1+solver(root->right,height);
        return max(left,right);
    }

};
