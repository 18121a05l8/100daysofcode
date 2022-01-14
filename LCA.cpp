/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *ans=NULL;
    bool solve(TreeNode *root,TreeNode *n1,TreeNode *n2)
    {
        if(root==NULL)
            return false;
        int left=solve(root->left,n1,n2);
        int right=solve(root->right,n1,n2);
        int curr=(root->val==n1->val or root->val==n2->val);
        if(curr+left+right>=2)
            ans=root;
        return (left+right+curr>0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};
