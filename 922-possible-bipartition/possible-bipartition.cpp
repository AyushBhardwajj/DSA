class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);

        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> vis(n+1,0);

        for(int i=1;i<=n;i++){

            if(vis[i]==1)continue;

            queue<pair<int,int>> q;
            q.push({i,0});

            vector<int> color(n+1,0);
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto it:adj[node]){
                    if(!vis[it]){
                        color[it] = !col;
                        vis[it]=1;
                        q.push({it,color[it]});
                    }

                    else{
                        if(color[node] == color[it])return false;
                    }
                }
            }
        }

        return true;
    }
};