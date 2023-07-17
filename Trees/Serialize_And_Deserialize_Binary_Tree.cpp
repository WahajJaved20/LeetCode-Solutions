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
    void encode(TreeNode* root, ostringstream& out) {
        if (root == NULL) {
            out << "N ";
            return;
        }
        
        out << root->val << " ";
        
        encode(root->left, out);
        encode(root->right, out);
    }
    TreeNode* decode(istringstream& in) {
        string value = "";
        in >> value;
        
        if (value == "N") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(value));
        
        root->left = decode(in);
        root->right = decode(in);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       istringstream in(data);
        return decode(in);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
