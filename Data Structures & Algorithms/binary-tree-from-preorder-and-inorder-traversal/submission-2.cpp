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
    unordered_map<int,int> map;
    int root=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            map[inorder[i]]=i;
        }
        return solver(preorder,inorder,0,n-1);
        
    }
    TreeNode* solver(vector<int>& preorder,vector<int>& inorder,int i,int j)
    {
        if(i>j) return NULL;
        int curr=map[preorder[root]];
        TreeNode* node=new TreeNode(preorder[root]);
        root++;
        TreeNode* left=solver(preorder,inorder,i,curr-1);
        TreeNode* right=solver(preorder,inorder,curr+1,j);
        node->left=left;
        node->right=right;
        return node;
    }
};
