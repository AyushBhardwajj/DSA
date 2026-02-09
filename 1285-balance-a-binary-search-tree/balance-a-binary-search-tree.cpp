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
    void solve(TreeNode* root ,vector<int> &vec){
        if(root == nullptr)return;

        vec.push_back(root->val);
        solve(root->left,vec);
        solve(root->right,vec);
    }

    int ind = 0;

    TreeNode* solve2(vector<int> &vec,int start,int end){
        if(start>end)return nullptr;

        int mid = start + (end-start)/2;

        TreeNode* root = new TreeNode(vec[mid]);

        root->left = solve2(vec,start,mid-1);
        root->right = solve2(vec,mid+1,end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        solve(root,vec);
        sort(vec.begin(),vec.end());
        int k = vec.size();

        return solve2(vec,0,k-1);
    }
};