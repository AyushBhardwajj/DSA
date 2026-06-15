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
    int solve(TreeNode* root,int level,map<int,multiset<int>> &mt,vector<int> &dp){
        if(root==NULL)return 0;

        int left = solve(root->left,level+1,mt,dp);
        int right = solve(root->right,level+1,mt,dp);

        int ht = max(left,right);
        mt[level].insert(ht);

        if(mt[level].size()>2)mt[level].erase(mt[level].begin());

        dp[root->val] = ht;

        return 1+ht;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<int,multiset<int>> mt;
        vector<int> lvl(1e5+1,0);
        vector<int> dp(1e5+1,0);

        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;

        while(!q.empty()){
            int siz = q.size();

            for(int i=0;i<siz;i++){
                TreeNode* node = q.front();
                q.pop();
                int data = node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                lvl[data] = cnt;
            }
            cnt++;
        }

        solve(root,0,mt,dp);

        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            int data = queries[i];
            int level = lvl[data];
            int height = dp[data];

            auto it = mt[level].find(height);

            if(it!=mt[level].end())mt[level].erase(it);

            if(mt[level].size()==0){
                ans.push_back(level-1);
            }
            else{
                int newHtt = *prev(mt[level].end());
                ans.push_back(level+newHtt);
            }

            mt[level].insert(height);

            if(mt[level].size()>2)mt[level].erase(mt[level].begin());

        }

        return ans;
    }
};