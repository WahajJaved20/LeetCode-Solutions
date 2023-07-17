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
    bool isValidBST(TreeNode* root) {
        return checkBST(root,LONG_MIN,LONG_MAX);
    }
    bool checkBST(TreeNode* root, long lowerBound, long upperBound){
        if(!root){
            return true;
        }
        if(root->val <= lowerBound || root->val >= upperBound){
            return false;
        }
        return checkBST(root->left,lowerBound,root->val) && checkBST(root->right,root->val,upperBound);
    }
};
