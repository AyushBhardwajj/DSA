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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* terminate = root->left;
                while(terminate->right!=root && terminate->right!=NULL){
                    terminate = terminate->right;
                }

                if(terminate->right == root){
                    ans.push_back(root->val);
                    terminate->right = NULL;
                    root = root->right;
                }
                else{
                    terminate->right = root;
                    root = root->left;
                }
            }
        }

        return ans;
    }
};