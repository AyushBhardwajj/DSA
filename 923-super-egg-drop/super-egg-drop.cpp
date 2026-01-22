class Solution {
public:
    
    int solve(int k,int n,vector<vector<int>> &dp){
        if(k==1)return n;
        if(n<=1)return n;

        if(dp[k][n] != -1)return dp[k][n];

        int mint = INT_MAX;
        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            int x = solve(k-1,mid,dp);
            int y = solve(k,n-mid-1,dp);

            if(x < y){
                left = mid+1;
            }
            else{
                right = mid-1;
            }   
            
            int temp = max(x,y);
            mint = min(mint,temp);
        }

        return dp[k][n] = 1 + mint;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));

        return solve(k,n,dp);
    }
};