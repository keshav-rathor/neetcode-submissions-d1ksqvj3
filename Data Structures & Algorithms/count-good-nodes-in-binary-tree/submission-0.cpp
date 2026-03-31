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
        if(!root) return 0;
        
        // int maxi=max(maxi,root->val);
        solver(root,root->val);
        return ans;   
    }
    void solver(TreeNode* root,int maxi)
    {
        if(!root) return;

        if(root->val>=maxi) 
        {
            ans+=1;
            
        }
        maxi=max(maxi,root->val);
        solver(root->left,maxi);
        solver(root->right,maxi);
    }
};
