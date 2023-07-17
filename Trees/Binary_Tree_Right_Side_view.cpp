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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* rightSide = NULL;
            int length = q.size();
            for(int i=0;i<length;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current){
                    rightSide = current;
                    q.push(current->left);
                    q.push(current->right);
                }
            }
            if(rightSide){
                result.push_back(rightSide->val);
            }
        }
        return result;
    }
};
