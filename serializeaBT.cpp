/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "#";
        string temp=to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode *des(string &data)
    {
        if(data[0]=='#')
        {
            if(data.size()>1)
                data=data.substr(2);
            return NULL;
        }
        TreeNode *temp=new TreeNode(helper(data));
        temp->left=des(data);
        temp->right=des(data);
        return temp;
    }
    TreeNode* deserialize(string data) {
         return des(data);
    }
    private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
