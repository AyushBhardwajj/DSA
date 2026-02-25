class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj,string &labels,vector<int> &ans,int node,vector<int> &vis){
        vis[node]=1;
        vector<int> curr(26,0);

        for(auto it:adj[node]){
            if(!vis[it]){
                vector<int> ct = dfs(adj,labels,ans,it,vis);
                for(int i=0;i<26;i++){
                    curr[i]+=ct[i];
                }
            }
        }

        curr[labels[node]-'a']++;

        ans[node]+=curr[labels[node]-'a'];

        return curr;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> ans(n,0);
        vector<int> vis(n,0);

        dfs(adj,labels,ans,0,vis);

        return ans;
    }
};