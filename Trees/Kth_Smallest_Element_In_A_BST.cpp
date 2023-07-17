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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderArray;
        inOrder(root,inorderArray);
        return inorderArray[k-1];
    }
    void inOrder(TreeNode* root, vector<int>& inorderArray){
        if(!root){
            return;
        }
        inOrder(root->left,inorderArray);
        inorderArray.push_back(root->val);
        inOrder(root->right,inorderArray);
    }
};
