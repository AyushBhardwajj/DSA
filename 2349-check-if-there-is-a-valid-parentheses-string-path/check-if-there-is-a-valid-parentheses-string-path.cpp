class Solution {
public:
   
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if((n+m-1)%2 == 1)return false;

        int hf = (n+m-1)/2;

        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(m,vector<bool>(hf+1,false)));

        if(grid[0][0]==')' || grid[n-1][m-1]=='(')return false;

        dp[0][0][1] = true;
        int cntt = 1;

        for(int i=1;i<m;i++){
            if(grid[0][i]=='(')cntt++;
            else cntt--;

            if(cntt>=0 && cntt<=hf)dp[0][i][cntt]=true;
            else break;
        }

        cntt = 1;

        for(int j=1;j<n;j++){
            if(grid[j][0]=='(')cntt++;
            else cntt--;

            if(cntt>=0 && cntt<=hf)dp[j][0][cntt] = true;
            else break;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                for(int k=0;k<=hf;k++){
                    int cnt = k;
                    if(grid[i][j]=='(')cnt++;
                    else cnt--;
                    if(dp[i-1][j][k]==true){
                        if(cnt>=0 && cnt<=hf)dp[i][j][cnt] = true;
                    }

                    if(dp[i][j-1][k]==true){
                        if(cnt>=0 && cnt<=hf)dp[i][j][cnt] = true;
                    }
                    
                }
            }
        }

        //cout<<n<<" "<<m;

        return dp[n-1][m-1][0];

    }
};