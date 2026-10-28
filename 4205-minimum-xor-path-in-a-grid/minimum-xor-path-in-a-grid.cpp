class Solution {
public:
    int solve(vector<vector<int>> &grid,int r,int c,int xrr,vector<vector<vector<int>>> &dp){
        if(r==grid.size()-1 && c == grid[0].size()-1){
            int nxrr = xrr^grid[r][c];
            return nxrr;
        }

        if(dp[r][c][xrr]!=-1)return dp[r][c][xrr];

        int right = 1e9,down = 1e9;

        if(r<grid.size()-1){
            down = solve(grid,r+1,c,xrr^grid[r][c],dp);
        }
        if(c<grid[0].size()-1){
            right = solve(grid,r,c+1,xrr^grid[r][c],dp);
        }

        return dp[r][c][xrr] = min(right,down);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));

        return solve(grid,0,0,0,dp);
    }
};