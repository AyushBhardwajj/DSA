class Solution {
public:
    long long find(int i, int n, vector<int> &a, int j, int m, vector<int> &b, int k, vector<vector<vector<long long>>> &dp){
        if(k==0) return 0;
        if(i==n||j==m) return LLONG_MIN;
        if(dp[i][j][k]!=-1e18) return dp[i][j][k];
        long long ans1 = find(i+1,n,a,j,m,b,k,dp);
        long long ans2 = find(i,n,a,j+1,m,b,k,dp);
        long long ans3 = find(i+1,n,a,j+1,m,b,k-1,dp);
        if(ans3!=LLONG_MIN) ans3+=1ll*a[i]*b[j];
        return dp[i][j][k]=max({ans1,ans2,ans3});
    }
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+1,-1e18)));
        long long ans = find(0,n,a,0,m,b,k,dp);
        return ans;
    }
};