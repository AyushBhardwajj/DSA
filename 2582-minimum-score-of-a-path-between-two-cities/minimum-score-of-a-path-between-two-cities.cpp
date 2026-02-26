class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> dist(n+1,1e9);

        dist[1] = 0;

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        queue<int> q;

        int ans = 1e9;

        q.push(1);
        vector<int> vis(n+1,0);
        vis[1]=1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:adj[node]){
                ans = min(ans,it.second);
                if(vis[it.first])continue;
                vis[it.first]  =1;

                q.push(it.first);
            }
        }

        return ans;
    }
};