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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solver(p,q);

    }
    bool solver(TreeNode* p,TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val!=q->val) return false;
        
      
        // if(!p && !q) return true;


        bool left=solver(p->left, q->left);
        bool right=solver(p->right, q->right);
        return left && right;
    }
};
