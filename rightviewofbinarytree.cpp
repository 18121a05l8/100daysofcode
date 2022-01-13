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
    vector<int>ans;
    int max_level=INT_MIN;
    void solve(TreeNode *root,int curr)
    {
        if(root==NULL)
            return;
        if(curr>max_level)
        {
            ans.push_back(root->val);
            max_level=curr;
        }
        solve(root->right,curr+1);
        solve(root->left,curr+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};
