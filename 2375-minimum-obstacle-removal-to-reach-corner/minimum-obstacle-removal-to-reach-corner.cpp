class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,1e9));

        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;

        
        vis[0][0]=0;
        if(grid[0][0]==1){
            pq.push({1,0,0});
            vis[0][0]=1;
        }
        else pq.push({0,0,0});

        vector<int> dr = {-1,0,0,1};
        vector<int> dc = {0,-1,1,0};

        while(!pq.empty()){
            int dist = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            if(r == n-1 && c == m-1)return dist;

            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int tot = dist;
                    if(grid[nr][nc]==1){
                       tot++;
                    }
                    if(vis[nr][nc]>tot){
                        vis[nr][nc] = tot;
                        pq.push({tot,nr,nc});
                    }
                }
            }
        }

        return -1;
    }
};