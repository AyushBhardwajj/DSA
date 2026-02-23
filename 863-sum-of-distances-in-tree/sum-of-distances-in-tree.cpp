class Solution {
public:
    int solve(int node,vector<int> &subtree,int par,vector<vector<int>> &adj){
        int curr = 1;
        for(auto it:adj[node]){
            if(it!=par){
                curr+=solve(it,subtree,node,adj);
            }
        }

        return subtree[node] = curr;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> subtree(n,0);

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n,0);
        vis[0]=1;

        q.push({0,0});

        vector<int> dist(n,0);

        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            dist[0]+=dis;

            for(auto it :adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,dis+1});
                }
            }
        }

        cout<<dist[0]<<"\n";

        vis = {0};

        solve(0,subtree,-1,adj);

        for(auto it:adj[0]){
            q.push({it,0});
        }

        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            dist[node] = dist[par]-subtree[node]+(n-subtree[node]);
            q.pop();

            for(auto it:adj[node]){
                if(it!=par){
                    q.push({it,node});
                }
            }
        }

        //cout<<dist[0]<<" "<<subtree[1]<<" "<<n-subtree[1]<<"\n";

        // cout<<dist[1]<<"\n";

        return dist;
    }
};