class Solution {
public:
    bool solve(vector<vector<char>> &grid,int i,int j,stack<char> &st,int &cnt,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i==n-1 && j==m-1){
            if(cnt==1)return true;
            return false;
        }

        bool ans = false;

        if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
        }

        if(i+1<n){
            if(grid[i][j]=='('){
                cnt++;
                st.push(grid[i][j]);
                ans = ans || solve(grid,i+1,j,st,cnt,dp);
                st.pop();
                cnt--;
            }
            else{
                if(st.empty())return false;
                st.pop();
                cnt--;
                ans = ans || solve(grid,i+1,j,st,cnt,dp);
                cnt++;
                st.push('(');
            }
        }

        if(j+1<m){
            if(grid[i][j]=='('){
                cnt++;
                st.push(grid[i][j]);
                ans = ans || solve(grid,i,j+1,st,cnt,dp);
                st.pop();
                cnt--;
            }
            else{
                if(st.empty())return false;
                st.pop();
                cnt--;
                ans = ans || solve(grid,i,j+1,st,cnt,dp);
                cnt++;
                st.push('(');
            }
        }

        if(ans == true)dp[i][j][cnt] = 1;
        else dp[i][j][cnt]=0;

        return ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(202,-1)));

        if(grid[0][0]==')' || grid[n-1][m-1]=='(')return false;

        stack<char> st;
        int cnt = 0;

        return solve(grid,0,0,st,cnt,dp);

    }
};