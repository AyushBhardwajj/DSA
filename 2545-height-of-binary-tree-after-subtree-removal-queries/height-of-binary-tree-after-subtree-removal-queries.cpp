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
    int solve(TreeNode* root,vector<int> &dp,int cnt,map<int,multiset<int>> &mp,vector<int> &level){
        if(root == NULL)return 0;

        level[root->val] = cnt;

        int left = solve(root->left,dp,cnt+1,mp,level);
        int right = solve(root->right,dp,cnt+1,mp,level);

        int curr = 1+max(left,right);

        mp[cnt].insert(curr);

        return dp[root->val] = 1+max(left,right);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> dp(1e5+1,0);
        vector<int> level(1e5+1,0);
        map<int,multiset<int>> mt2;
        vector<int> ans;

        int maxt = solve(root,dp,0,mt2,level);

        for(int i=0;i<queries.size();i++){
            int node = queries[i];

            int lvl = level[node];

            int ht = dp[node];

            auto it = mt2[lvl].find(ht);

            mt2[lvl].erase(it);

            if(mt2[lvl].empty()){
                ans.push_back(lvl-1);
            } 
            else{
                int val = *mt2[lvl].rbegin();
                ans.push_back(lvl+val-1);
            }

            mt2[lvl].insert(ht);
        }

        return ans;

    }
};