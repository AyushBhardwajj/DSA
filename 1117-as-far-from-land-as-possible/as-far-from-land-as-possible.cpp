class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int dis = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
                else cnt++;
            }
        }

        if(q.empty() || (cnt==0))return -1;

        vector<int> dr = {-1,0,0,1};
        vector<int> dc = {0,1,-1,0};

        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j=0;j<4;j++){
                    int nr = r+dr[j];
                    int nc = c+dc[j];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && !vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }

            dis++;
        }

        dis--;
        return dis;
    }
};