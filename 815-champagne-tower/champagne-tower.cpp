class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>> dp(102,vector<double>(102,0.00));

        double curr = poured;
        dp[0][0] = curr;

        for(int i=1;i<=100;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    if(dp[i-1][j]>1.00)dp[i][j] = (dp[i-1][j]-1)/2.00;
                }
                else if(j==i){
                    if(dp[i-1][j-1]>1.00)dp[i][j] = (dp[i-1][j-1]-1)/2.00;
                }

                else{
                    if(dp[i-1][j]>1.00)dp[i][j] = (dp[i-1][j]-1)/2.00;
                    if(dp[i-1][j-1]>1.00)dp[i][j]+=(dp[i-1][j-1]-1)/2.00;
                }

            }
        }

        return min(1.000,dp[query_row][query_glass]);
    }
};