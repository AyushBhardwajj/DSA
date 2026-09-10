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

    pair<int,int> solve(TreeNode* root,int &ans){
        if(root == NULL)return {0,0};

        pair<int,int> left = solve(root->left,ans);
        pair<int,int> right = solve(root->right,ans);

        int sum = left.first+right.first;
        int cnt = left.second + right.second;

        sum+=root->val;
        cnt++;

        int avg = sum/cnt;

        int curr = root->val;

        if(avg == curr)ans++;

        return {sum,cnt};
    }
    

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        solve(root,ans);

        return ans;
    }
};