class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(k+1,vector<long long>(n,0));

        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }

        long long mod = 1e9+7;

        for(int i=1;i<=k;i++){
            for(int j=i;j<n;j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i][j-1])%mod;
            }

            for(int j=1;j<n;j++){
                dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            }
        }

        // for(int i=0;i<=k;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        return dp[k][n-1];


    }
};