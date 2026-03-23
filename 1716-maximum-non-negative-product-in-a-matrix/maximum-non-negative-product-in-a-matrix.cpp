class Solution {
public:
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long mod = 1e9+7;

        vector<vector<pair<long long,long long>>> dp(n,vector<pair<long long,long long>>(m,{-1ll,-1ll}));

        if(grid[0][0]<0){
            dp[0][0].second = -grid[0][0];
        }else{
            dp[0][0].first = grid[0][0];
        }

        for(int i=1;i<m;i++){
            long long curr = grid[0][i];

            if(dp[0][i-1].first>=0){
                if(curr<0){
                    dp[0][i].second = (-1ll*dp[0][i-1].first*curr);
                }
                else if(curr == 0){
                    dp[0][i].second = 0;
                    dp[0][i].first = 0;
                }
                else{
                    dp[0][i].first = (dp[0][i-1].first*curr);
                }
            }
            if(dp[0][i-1].second>=0){
                if(curr<0){
                    dp[0][i].first = max(dp[0][i].first,(-1ll*dp[0][i-1].second*curr));
                }
                else if(curr == 0){
                    dp[0][i].first = max(dp[0][i].first,0ll);
                    dp[0][i].second = max(dp[0][i].second,0ll);
                }
                else{
                    dp[0][i].second = max(dp[0][i].second,(dp[0][i-1].second*curr));
                }
            }
        }

        for(int i=1;i<n;i++){
            long long curr = grid[i][0];

            if(dp[i-1][0].first>=0){
                if(curr<0){
                    dp[i][0].second = (-1ll*dp[i-1][0].first*curr);
                }
                else if(curr == 0){
                    dp[i][0].second = 0;
                    dp[i][0].first = 0;
                }
                else{
                    dp[i][0].first = (dp[i-1][0].first*curr);
                }
            }

            if(dp[i-1][0].second>=0){
                if(curr<0){
                    dp[i][0].first = max(dp[i][0].first,(-1ll*dp[i-1][0].second*curr));
                }
                else if(curr == 0){
                    dp[i][0].first = max(dp[i][0].first,0ll);
                    dp[i][0].second = max(dp[i][0].second,0ll);
                }
                else{
                    dp[i][0].second = max(dp[i][0].second,(dp[i-1][0].second*curr));
                }
            }

        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long pos = max(dp[i-1][j].first,dp[i][j-1].first);
                long long neg = max(dp[i-1][j].second,dp[i][j-1].second);
                long long curr = grid[i][j];

                if(pos>=0){
                    if(curr<0){
                        dp[i][j].second = (-1ll*pos*curr);
                    }
                    else if(curr == 0){
                        dp[i][j].first = max(dp[i][j].first,0ll);
                        dp[i][j].second = max(dp[i][j].second,0ll);
                    }
                    else{
                        dp[i][j].first = pos*curr;
                    }
                }
                if(neg>=0){
                    if(curr<0){
                        dp[i][j].first = max(dp[i][j].first,(-1ll*neg*curr));
                    }
                    else if(curr == 0){
                        dp[i][j].first = max(dp[i][j].first,0ll);
                        dp[i][j].second = max(dp[i][j].second,0ll);
                    }
                    else{
                        dp[i][j].second = max(dp[i][j].second,neg*curr);
                    }
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j].first<<" "<<dp[i][j].second<<"     ";
        //     }
        //     cout<<"\n";
        // }


        if(dp[n-1][m-1].first<0)return -1;

        return dp[n-1][m-1].first%mod;


    }
};