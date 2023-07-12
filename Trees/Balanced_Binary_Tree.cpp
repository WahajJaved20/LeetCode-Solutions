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
    bool isBalanced(TreeNode* root) {
        pair<bool,int> res = DFS(root);
        return res.first;
    }
    pair<bool,int> DFS(TreeNode* root){
        if(!root){
            return pair<bool,int>(true,-1);
        }
        pair<bool,int> leftSol = DFS(root->left);
        pair<bool,int> rightSol = DFS(root->right);
        if(!leftSol.first || !rightSol.first){
            return pair<bool,int>(false,1+max(leftSol.second,rightSol.second));
        }
        if(abs(leftSol.second - rightSol.second) <= 1){
            return pair<bool,int>(true,1+max(leftSol.second,rightSol.second));
        }else{
            return pair<bool,int>(false,1+max(leftSol.second,rightSol.second));
        }
    }
};
