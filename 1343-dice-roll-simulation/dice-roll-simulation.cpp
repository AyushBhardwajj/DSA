class Solution {
public:
    long long solve(int n,int prev,int tim, vector<int> &arr,vector<vector<vector<long long>>> &dp){
        if(n==0)return 1;

        long long mod = 1e9+7;

        if(dp[n][prev][tim]!=-1)return dp[n][prev][tim];

        long long ans = 0;

        for(int i=1;i<=6;i++){
            if((i == prev) && (tim<arr[i-1])){
                ans  =  (ans+solve(n-1,prev,tim+1,arr,dp))%mod;
            }
            else if(i!=prev){
                ans  = (ans + solve(n-1,i,1,arr,dp))%mod;
            }
        }

        return dp[n][prev][tim] =  ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {

        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(7,vector<long long>(16,-1)));
        
        return (int)solve(n,0,0,rollMax,dp);
    }
};