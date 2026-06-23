class Solution {
public:
    bool solve(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis,char &ch){
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};

        vis[i][j] = 1;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,pair<int,pair<int,int>>>> q;
        q.push({i,{j,{-1,-1}}});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second.first;
            int pr = q.front().second.second.first;
            int pc = q.front().second.second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+di[i];
                int nc = c+dj[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==ch){
                    if(nr==pr && nc==pc)continue;
                    if(vis[nr][nc])return true;
                    q.push({nr,{nc,{r,c}}});
                    vis[nr][nc]=1;
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(solve(i,j,grid,vis,grid[i][j]))return true;
                }
            }
        }

        return false;
    }
};