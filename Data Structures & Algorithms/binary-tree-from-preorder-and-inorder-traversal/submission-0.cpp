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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int ind=0;
        return solver(preorder,inorder,ind,0,n-1);
    }
    TreeNode* solver(vector<int>& preorder, vector<int>& inorder,int &ind,int left,int right)
    {
        if(left>right) return NULL;
        int i=left;
        while(inorder[i]!=preorder[ind]) i++;
        ind++;
        TreeNode* node=new TreeNode(inorder[i]);
        node->left=solver(preorder,inorder,ind,left,i-1);
        node->right=solver(preorder,inorder,ind,i+1,right);
        return node;
    }
};
