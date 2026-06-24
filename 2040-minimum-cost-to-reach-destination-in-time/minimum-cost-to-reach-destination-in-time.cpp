class Solution {
public:
    int solve(vector<int> &passingFees,vector<vector<pair<int,int>>> &adj,int maxt,int node,int final,vector<vector<int>> &dp){
        if(node == final){
            return passingFees[final];
        }

        if(dp[node][maxt]!=-1)return dp[node][maxt];

        int ans = 1e9;

        for(auto it:adj[node]){
            if(maxt<it.second)continue;
            int curr = passingFees[node]+solve(passingFees,adj,maxt-it.second,it.first,final,dp);
            ans = min(ans,curr);
        }

        return dp[node][maxt] =ans;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();

        vector<int> cost(n,1e9);

        cost[0] = passingFees[0];

        vector<vector<int>> dp(n,vector<int>(maxTime+1,-1));

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        int ans = solve(passingFees,adj,maxTime,0,n-1,dp);

        return ans>=1e9?-1:ans;
    }
};