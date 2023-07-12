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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDiameter(root);
        return diameter;
    }
    int calculateDiameter(TreeNode* root){
        if(!root){
            return -1;
        }
        int leftHeight = calculateDiameter(root->left);
        int rightHeight = calculateDiameter(root->right);
        int diam = leftHeight + rightHeight + 2;
        diameter = max(diam,diameter);
        return max(leftHeight,rightHeight) + 1;
    }
};
