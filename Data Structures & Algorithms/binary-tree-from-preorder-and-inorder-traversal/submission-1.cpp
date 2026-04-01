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
    int curr=0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        for(int i=0;i<n;i++) map[inorder[i]]=i;
        return solver(preorder,0,n-1);
    }
    TreeNode* solver(vector<int>& preorder,int l,int h)
    {
        if(l>h) return NULL;


        int index=map[preorder[curr]];
        TreeNode* root=new TreeNode(preorder[curr]);
        curr++;

        TreeNode* left=solver(preorder,l,index-1);
        TreeNode* right=solver(preorder,index+1,h);
        root->left=left;
        root->right=right;

        return root;
    }
};
