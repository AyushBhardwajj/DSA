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
    void solve(TreeNode* root,long long &ans,vector<int> &trav){\

        if(root==nullptr)return;

        if(root->left == nullptr && root->right==nullptr){
            trav.push_back(root->val);
            long long valt = 0;

            for(int i=0;i<trav.size();i++){
                valt = 2*valt+trav[i];
            }

            trav.pop_back();

            ans+=valt;

            return;
        }

        trav.push_back(root->val);

        solve(root->left,ans,trav);
        solve(root->right,ans,trav);

        trav.pop_back();
        
        
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> trav;
        long long ans = 0;

        // if(root==nullptr)return 0;

        solve(root,ans,trav);

        return ans;
    }
};