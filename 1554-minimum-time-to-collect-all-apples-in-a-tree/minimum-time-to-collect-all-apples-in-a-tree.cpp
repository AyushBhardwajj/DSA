class Solution {
public:
    
    int dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<bool> &app){
        vis[node] = 1;

        int ans = 0;

        for(auto it:adj[node]){
            if(!vis[it]){
                int curr = dfs(it,adj,vis,app);
                ans+=curr;
            }
        }

        if(ans!=0 || app[node])ans+=2;

        cout<<node<<" "<<ans<<"\n";
        

        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,0);

        return max(0,dfs(0,adj,vis,hasApple)-2);
    }
};