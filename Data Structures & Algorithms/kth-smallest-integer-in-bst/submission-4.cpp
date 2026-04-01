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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        ans=-1;
        int ind=0;
        solver(root,k,ind);
        return ans;

    }
    void solver(TreeNode* root,int k, int& ind)
    {
        if(!root) return;
        solver(root->left,k,ind);
        ind++;
        if(ind==k)
        {
            ans=root->val;
            
            return;
        }
      
        solver(root->right,k,ind);
    }
};
