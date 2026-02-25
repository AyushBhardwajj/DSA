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
    
    void solve(vector<TreeNode*> &ans,TreeNode* root,set<int> &st){
        if(root == nullptr)return;

        solve(ans,root->left,st);
        solve(ans,root->right,st);

        if(st.find(root->val)!=st.end()){
            if(root->right && st.find(root->right->val)==st.end())ans.push_back(root->right);
            if(root->left && st.find(root->left->val) == st.end())ans.push_back(root->left);
        }

        if(root->left && st.find(root->left->val)!=st.end()){
            root->left = nullptr;
        }

        if(root->right && st.find(root->right->val)!=st.end()){
            root->right = nullptr;
        }

    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        set<int> st;

        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }

        solve(ans,root,st);
        if(st.find(root->val)==st.end())ans.push_back(root);

        return ans;
    }
};